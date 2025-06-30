#include "s21_cat.h"

void CatSetTable(const char *table[static 256]) {
  const char *badTable[] = {
      "\00",  "\01",  "\02",  "\03",  "\04",  "\05",  "\06",  "\07",  "\b",
      "\t",   "\n",   "\v",   "\014", "\r",   "\016", "\017", "\020", "\021",
      "\022", "\023", "\024", "\025", "\026", "\027", "\030", "\031", "\032",
      "\033", "\034", "\035", "\036", "\037", " ",    "!",    "\"",   "#",
      "$",    "%",    "&",    "\'",   "(",    ")",    "*",    "+",    ",",
      "-",    ".",    "/",    "0",    "1",    "2",    "3",    "4",    "5",
      "6",    "7",    "8",    "9",    ":",    ";",    "<",    "=",    ">",
      "?",    "@",    "A",    "B",    "C",    "D",    "E",    "F",    "G",
      "H",    "I",    "J",    "K",    "L",    "M",    "N",    "O",    "P",
      "Q",    "R",    "S",    "T",    "U",    "V",    "W",    "X",    "Y",
      "Z",    "[",    "\\",   "]",    "^",    "_",    "`",    "a",    "b",
      "c",    "d",    "e",    "f",    "g",    "h",    "i",    "j",    "k",
      "l",    "m",    "n",    "o",    "p",    "q",    "r",    "s",    "t",
      "u",    "v",    "w",    "x",    "y",    "z",    "{",    "|",    "}",
      "~",    "\x7f", "\x80", "\x81", "\x82", "\x83", "\x84", "\x85", "\x86",
      "\x87", "\x88", "\x89", "\x8a", "\x8b", "\x8c", "\x8d", "\x8e", "\x8f",
      "\x90", "\x91", "\x92", "\x93", "\x94", "\x95", "\x96", "\x97", "\x98",
      "\x99", "\x9a", "\x9b", "\x9c", "\x9d", "\x9e", "\x9f", "\xa0", "\xa1",
      "\xa2", "\xa3", "\xa4", "\xa5", "\xa6", "\xa7", "\xa8", "\xa9", "\xaa",
      "\xab", "\xac", "\xad", "\xae", "\xaf", "\xb0", "\xb1", "\xb2", "\xb3",
      "\xb4", "\xb5", "\xb6", "\xb7", "\xb8", "\xb9", "\xba", "\xbb", "\xbc",
      "\xbd", "\xbe", "\xbf", "\xc0", "\xc1", "\xc2", "\xc3", "\xc4", "\xc5",
      "\xc6", "\xc7", "\xc8", "\xc9", "\xca", "\xcb", "\xcc", "\xcd", "\xce",
      "\xcf", "\xd0", "\xd1", "\xd2", "\xd3", "\xd4", "\xd5", "\xd6", "\xd7",
      "\xd8", "\xd9", "\xda", "\xdb", "\xdc", "\xdd", "\xde", "\xdf", "\xe0",
      "\xe1", "\xe2", "\xe3", "\xe4", "\xe5", "\xe6", "\xe7", "\xe8", "\xe9",
      "\xea", "\xeb", "\xec", "\xed", "\xee", "\xef", "\xf0", "\xf1", "\xf2",
      "\xf3", "\xf4", "\xf5", "\xf6", "\xf7", "\xf8", "\xf9", "\xfa", "\xfb",
      "\xfc", "\xfd", "\xfe", "\xff"};
  memcpy(table, badTable, sizeof badTable);
}

void CatSet_V(const char *table[static 256]) {
  const char *table1[] = {"^@", "^A", "^B", "^C", "^D", "^E", "^F", "^G", "^H"};
  const char *table2[] = {"^K", "^L", "^M", "^N",  "^O", "^P", "^Q",
                          "^R", "^S", "^T", "^U",  "^V", "^W", "^X",
                          "^Y", "^Z", "^[", "^\\", "^]", "^^", "^_"};
  const char *table3[] = {
      "^?",   "M-^@", "M-^A",  "M-^B", "M-^C", "M-^D", "M-^E", "M-^F", "M-^G",
      "M-^H", "M-^I", "M-^J",  "M-^K", "M-^L", "M-^M", "M-^N", "M-^O", "M-^P",
      "M-^Q", "M-^R", "M-^S",  "M-^T", "M-^U", "M-^V", "M-^W", "M-^X", "M-^Y",
      "M-^Z", "M-^[", "M-^\\", "M-^]", "M-^^", "M-^_", "M- ",  "M-!",  "M-\"",
      "M-#",  "M-$",  "M-%",   "M-&",  "M-'",  "M-(",  "M-)",  "M-*",  "M-+",
      "M-,",  "M--",  "M-.",   "M-/",  "M-0",  "M-1",  "M-2",  "M-3",  "M-4",
      "M-5",  "M-6",  "M-7",   "M-8",  "M-9",  "M-:",  "M-;",  "M-<",  "M-=",
      "M->",  "M-?",  "M-@",   "M-A",  "M-B",  "M-C",  "M-D",  "M-E",  "M-F",
      "M-G",  "M-H",  "M-I",   "M-J",  "M-K",  "M-L",  "M-M",  "M-N",  "M-O",
      "M-P",  "M-Q",  "M-R",   "M-S",  "M-T",  "M-U",  "M-V",  "M-W",  "M-X",
      "M-Y",  "M-Z",  "M-[",   "M-\\", "M-]",  "M-^",  "M-_",  "M-`",  "M-a",
      "M-b",  "M-c",  "M-d",   "M-e",  "M-f",  "M-g",  "M-h",  "M-i",  "M-j",
      "M-k",  "M-l",  "M-m",   "M-n",  "M-o",  "M-p",  "M-q",  "M-r",  "M-s",
      "M-t",  "M-u",  "M-v",   "M-w",  "M-x",  "M-y"};
  memcpy(table, table1, sizeof table1);
  memcpy(&table[11], table2, sizeof table2);
  memcpy(&table['~' + 1], table3, sizeof table3);
}

void Flag_T(const char *table[static 256]) { table['\t'] = "^I"; }

void Flag_E(const char *table[static 256]) { table['\n'] = "$\n"; }

AllFlags ReadFlags(int argc, char **argv, int *flag_out) {
  opterr = 0;
  AllFlags SensorFlags = {0, 0, 0, 0, 0, 0};
  struct option longopts[] = {{"number-nonblank", 0, NULL, 'b'},
                              {"number", 0, NULL, 'n'},
                              {"squeeze-blank", 0, NULL, 's'},
                              {NULL, 0, NULL, 0}};
  int FlagNow = 0;

  while (
      ((FlagNow = getopt_long(argc, argv, "bevEnstT", longopts, NULL)) != -1) &&
      *flag_out == 0) {
    switch (FlagNow) {
      case 'b':
        SensorFlags.flag_b = 1;
        break;
      case 'e':
        SensorFlags.flag_e = 1;
        SensorFlags.flag_v = 1;
        break;
      case 'v':
        SensorFlags.flag_v = 1;
        break;
      case 'E':
        SensorFlags.flag_e = 1;
        break;
      case 'n':
        SensorFlags.flag_n = 1;
        break;
      case 's':
        SensorFlags.flag_s = 1;
        break;
      case 't':
        SensorFlags.flag_t = 1;
        SensorFlags.flag_v = 1;
        break;
      case 'T':
        SensorFlags.flag_t = 1;
        break;
      case '?':
        printf("cat: неверный ключ — «%c»\n", optopt);
        printf(
            "По команде «cat --help» можно получить дополнительную "
            "информацию.\n");
        *flag_out = 1;
        break;
      default:
        printf("Unknow error\n");
        break;
    }
  }
  return SensorFlags;
}

void CatFile(FILE **file, AllFlags flags, const char *table[static 256],
             int *lines, int *empty_line_file) {
  int c = 0;
  (void)(*empty_line_file);
  int last = 0;
  int first = 0;
  int empty = 0;
  if (flags.flag_b && flags.flag_n) flags.flag_b = false;

  while (fread(&c, 1, 1, *file) > 0) {
    if (first == 0 && (*empty_line_file) == 1 && c == '\n') continue;
    if (last == '\n') {
      if (flags.flag_s && c == '\n') {
        if (empty) continue;
        empty = 1;
        (*empty_line_file)++;
      } else {
        empty = 0;
        (*empty_line_file) = 0;
      }
      if (flags.flag_b) {
        if (c != '\n') printf("%6i\t", (*lines)++);
      } else if (flags.flag_n) {
        printf("%6i\t", (*lines)++);
      }
    }
    if (first == 0) {
      if (flags.flag_b) {
        if (c != '\n') printf("%6i\t", (*lines)++);
      } else if (flags.flag_n) {
        printf("%6i\t", (*lines)++);
      }
      first++;
    }
    if (!*table[c])
      printf("%c", '\0');
    else
      printf("%s", table[c]);
    last = c;
  }
}

int search_flags(int argc, char **argv) {
  int count = 1;
  int flag = 1;
  while (count < argc) {
    if (argv[count][0] != '-') {
      count = argc;
      flag = 0;
    }
    ++count;
  }
  return flag;
}

void Cat(int argc, char *argv[], AllFlags flags, const char *table[static 256],
         int optind) {
  if (argc == 1) {
    char buffer[4096] = {0};
    while (fgets(buffer, 4096, stdin) != NULL) {
      printf("%s", buffer);
    }
  }
  int lines = 1;
  int empty_line_file = 0;
  int condition = 0;
  for (char **filename = &argv[optind], **end = &argv[argc]; filename != end;
       ++filename) {
    condition = 1;
    char buffer[4096] = {0};
    FILE *ch = fopen(*filename, "rb");

    if (strcmp("-", *filename) == 0) {
      while (fgets(buffer, 4096, stdin) != NULL) {
        printf("%s", buffer);
      }
    }

    else if (ch == NULL) {
      printf("cat: %s: Нет такого файла или каталога\n", *filename);
      continue;
    } else {
      CatFile(&ch, flags, table, &lines, &empty_line_file);
    }
    if (ch != NULL) fclose(ch);
  }
  if (argv[optind] == argv[argc] && condition == 0)
    printf("Я не делал такой крутой stdin ;D\n");
}
