#ifndef CAT_H
#define CAT_H
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  bool flag_b;
  bool flag_e;
  bool flag_v;
  bool flag_n;
  bool flag_s;
  bool flag_t;
} AllFlags;

void CatSetTable(const char *table[static 256]);
void Flag_T(const char *table[static 256]);
void Flag_E(const char *table[static 256]);
void CatSet_V(const char *table[static 256]);
AllFlags ReadFlags(int argc, char **argv, int *flag_out);
void CatFile(FILE **file, AllFlags flags, const char *table[static 256],
             int *lines, int *empty_line_file);
void Cat(int argc, char *argv[], AllFlags flags, const char *table[static 256],
         int optind);
int search_flags(int argc, char **argv);

#endif