#include "s21_grep.h"

void Optargunion(AllFlags *flags, size_t *Msize, char const *target,
                 size_t size_target) {
  flags->Mpattern = realloc(flags->Mpattern, *Msize + size_target + 7);
  flags->Mpattern[*Msize] = '\\';
  flags->Mpattern[*Msize + 1] = '|';
  flags->Mpattern[*Msize + 2] = '\\';
  flags->Mpattern[*Msize + 3] = '(';
  memcpy(flags->Mpattern + *Msize + 4, target, size_target);
  *Msize += size_target + 4;
  flags->Mpattern[*Msize] = '\\';
  flags->Mpattern[*Msize + 1] = ')';
  flags->Mpattern[*Msize + 2] = '\0';
  *Msize += 2;
}

void filePattern(AllFlags *flags, size_t *sizeLp, char const *target) {
  FILE *ch = fopen(target, "rb");
  if (ch == NULL) {
    printf("grep: %s: Нет такого файла или каталога\n", target);
  } else {
    char *line = NULL;
    size_t length = 0;
    int many = 0;

    while ((many = getline(&line, &length, ch)) > 0) {
      if (*line != '\n') {
        line[strcspn(line, "\n")] = '\0';
        flags->patternfile = realloc(flags->patternfile, *sizeLp + many + 7);
        flags->patternfile[*sizeLp] = '\\';
        flags->patternfile[*sizeLp + 1] = '|';
        flags->patternfile[*sizeLp + 2] = '\\';
        flags->patternfile[*sizeLp + 3] = '(';
        memcpy(flags->patternfile + *sizeLp + 4, line, many);
        *sizeLp += (many + 3);
        flags->patternfile[*sizeLp] = '\\';
        flags->patternfile[*sizeLp + 1] = ')';
        flags->patternfile[*sizeLp + 2] = '\0';
        *sizeLp += 2;
      }
    }
    if (ch != NULL) fclose(ch);
    free(line);
  }
}

void ReadFlags(int argc, char **argv, AllFlags *flags, int *flag_out) {
  char FlagNow = 0;
  flags->Mpattern = malloc(2);
  flags->Mpattern[0] = '\\';
  flags->Mpattern[1] = '\0';
  size_t pattern_size = 0;

  flags->patternfile = malloc(2);
  flags->patternfile[0] = '\\';
  flags->patternfile[1] = '\0';
  size_t fpattern_size = 0;
  opterr = 0;
  while ((FlagNow = getopt_long(argc, argv, "e:ivclnohsf:", 0, 0)) != -1) {
    switch (FlagNow) {
      case 'e':
        Optargunion(flags, &pattern_size, optarg, strlen(optarg));
        break;
      case 'i':
        flags->regex_flag |= REG_ICASE;
        break;
      case 'v':
        flags->invert = true;
        break;
      case 'c':
        flags->count = true;
        break;
      case 'l':
        flags->filesMatch = true;
        break;
      case 'n':
        flags->numberLine = true;
        break;
      case 'o':
        flags->printMatched = true;
        break;
      case 'h':
        flags->onlyline = true;
        break;
      case 's':
        flags->nonstop = true;
        break;
      case 'f':
        filePattern(flags, &fpattern_size, optarg);
        break;
      case '?':
        printf("grep: неверный ключ — «%c»\n", optopt);
        *flag_out = 1;
        break;
      default:
        printf("Try 'grep --help' for more information.\n");
        *flag_out = 1;
        break;
    }
  }
  if (pattern_size) {
    flags->Msize = pattern_size;
  }
  if (fpattern_size) {
    flags->Fsize = fpattern_size;
  }
}

int checkPattern(int *argc, char **argv[], int optind, AllFlags *flags) {
  int count_files = 0;
  *argv += optind;
  *argc -= optind;
  if (*argc == 0) {
    fprintf(stderr, "No pattern or file\n");
    count_files = -1;
    free(flags->Mpattern);
    free(flags->patternfile);
  } else if (flags->Msize || flags->Fsize)
    count_files = *argc;
  else
    count_files = *argc - 1;

  return count_files;
}

void GrepCount(FILE *file, char const *filename, AllFlags flags, regex_t *preg,
               int count_file) {
  char *line = 0;
  (void)flags;
  size_t length = 0;
  regmatch_t match;
  int count = 0;
  while (getline(&line, &length, file) > 0) {
    if ((!regexec(preg, line, 1, &match, 0))) {
      count++;
    }
  }
  if (count_file == 1)
    printf("%i\n", count);
  else
    printf("%s:%i\n", filename, count);
  free(line);
}

void Grep(int argc, char *argv[], AllFlags *flags, int count_files) {
  char **end = &argv[argc];
  regex_t preg_storage;
  regex_t *preg = &preg_storage;

  check_compilation(flags, argv, &preg);

  int sdvig = 1;

  if (flags->Msize || flags->Fsize) sdvig = 0;

  for (char **filename = argv + sdvig; filename != end; ++filename) {
    FILE *ch = fopen(*filename, "rb");
    if (ch == NULL) {
      if (flags->nonstop)
        continue;
      else {
        fprintf(stderr, "grep: %s: Нет такого файла или каталога\n", *filename);
        continue;
      }
    } else if (flags->count) {
      GrepCount(ch, *filename, *flags, preg, count_files);
      fclose(ch);
    } else if (flags->Fsize) {
      Patterfinder(ch, *flags, preg, *filename, count_files);
      fclose(ch);
    } else {
      GrepFile(ch, *flags, preg, *filename, count_files);
      fclose(ch);
    }
  }
  regfree(preg);
}

void GrepFile(FILE *file, AllFlags flags, regex_t *preg, char *filename,
              int count_files) {
  char *line = NULL;
  (void)flags;
  size_t length = 0;
  regmatch_t match;
  int strokaCounter = 0;
  int Match_helper = 1;
  while (getline(&line, &length, file) > 0) {
    strokaCounter++;
    line[strcspn(line, "\n")] = '\0';
    if (flags.invert)
      makeFlag_v(preg, count_files, &match, line, filename);
    else {
      if (!regexec(preg, line, 1, &match, 0)) {
        if (flags.printMatched) {
          if (count_files >= 2)
            printf("%s:%.*s\n", filename, (int)(match.rm_eo - match.rm_so),
                   line + match.rm_so);
          else
            printf("%.*s\n", (int)(match.rm_eo - match.rm_so),
                   line + match.rm_so);

          char *remaining = line + match.rm_eo;
          while (!regexec(preg, remaining, 1, &match, 0)) {
            if (count_files >= 2)
              printf("%s:%.*s\n", filename, (int)(match.rm_eo - match.rm_so),
                     remaining + match.rm_so);
            else
              printf("%.*s\n", (int)(match.rm_eo - match.rm_so),
                     remaining + match.rm_so);
            remaining = remaining + match.rm_eo;
          }
        } else if (flags.numberLine) {
          if (count_files >= 2)
            printf("%s:%i:%s\n", filename, strokaCounter, line);
          else
            printf("%i:%s\n", strokaCounter, line);
        } else if (flags.filesMatch && Match_helper == 1) {
          printf("%s\n", filename);
          Match_helper = 0;
        } else if (flags.onlyline) {
          printf("%s\n", line);
        } else {
          if (!flags.filesMatch) {
            if (count_files >= 2)
              printf("%s:%s\n", filename, line);
            else
              printf("%s\n", line);
          }
        }
      }
    }
  }
  free(line);
}

void Patterfinder(FILE *file, AllFlags flags, regex_t *preg, char *filename,
                  int count_files) {
  (void)flags;
  char *line = NULL;
  size_t length = 0;
  regmatch_t match;

  while (getline(&line, &length, file) > 0) {
    line[strcspn(line, "\n")] = '\0';
    if (!regexec(preg, line, 1, &match, 0)) {
      if (count_files >= 2)
        printf("%s:%s\n", filename, line);
      else
        printf("%s\n", line);
    }
  }
  free(line);
}

void check_compilation(AllFlags *flags, char *argv[], regex_t **preg) {
  if (flags->Msize == 0 && flags->Fsize == 0) {
    if (regcomp(*preg, argv[0], flags->regex_flag)) {
      fprintf(stderr, "faild to cimpile regex\n");
      free(flags->Mpattern);
      free(flags->patternfile);
      exit(1);
    }
  } else if (flags->Msize) {
    if (regcomp(*preg, flags->Mpattern + 2, flags->regex_flag)) {
      fprintf(stderr, "faild to cimpile regex\n");
      free(flags->Mpattern);
      free(flags->patternfile);
      exit(1);
    }
  } else if (flags->Fsize) {
    if (regcomp(*preg, flags->patternfile + 2, flags->regex_flag)) {
      fprintf(stderr, "faild to cimpile regex\n");
      free(flags->Mpattern);
      free(flags->patternfile);
      exit(1);
    }
  }
  free(flags->Mpattern);
  free(flags->patternfile);
}

void makeFlag_v(regex_t *preg, int count_files, regmatch_t *match, char *line,
                char *filename) {
  if (regexec(preg, line, 1, match, 0)) {
    if (count_files >= 2)
      printf("%s:%s\n", filename, line);
    else
      printf("%s\n", line);
  }
}
