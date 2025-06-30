#ifndef GREP_H
#define GREP_H
#define _GNU_SOURCE
#include <getopt.h>
#include <limits.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  char *Mpattern;
  size_t Msize;
  int regex_flag;
  bool invert;
  bool count;
  bool filesMatch;
  bool numberLine;
  bool printMatched;
  bool onlyline;
  bool nonstop;
  char *patternfile;
  size_t Fsize;
} AllFlags;

void ReadFlags(int argc, char **argv, AllFlags *flags, int *flag_out);
void Optargunion(AllFlags *flags, size_t *Msize, char const *target,
                 size_t size_target);
void filePattern(AllFlags *flags, size_t *Fsize, char const *target);
int checkPattern(int *argc, char **argv[], int optind, AllFlags *flags);
void GrepCount(FILE *file, char const *filename, AllFlags flags, regex_t *preg,
               int count_file);
void Grep(int argc, char *argv[], AllFlags *flags, int count_files);
void Patterfinder(FILE *file, AllFlags flags, regex_t *preg, char *filename,
                  int count_files);
void GrepFile(FILE *file, AllFlags flags, regex_t *preg, char *filename,
              int count_files);
void check_compilation(AllFlags *flags, char *argv[], regex_t **preg);
void makeFlag_v(regex_t *preg, int count_files, regmatch_t *match, char *line,
                char *filename);

#endif
