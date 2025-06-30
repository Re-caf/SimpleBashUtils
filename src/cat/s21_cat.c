#include "s21_cat.h"

int main(int argc, char *argv[]) {
  int flag_out = 0;
  const char *table[256];
  AllFlags flags = ReadFlags(argc, argv, &flag_out);
  if (flag_out != 1) {
    CatSetTable(table);
    if (flags.flag_n && flags.flag_b) flags.flag_n = false;
    if (flags.flag_e) Flag_E(table);
    if (flags.flag_t) Flag_T(table);
    if (flags.flag_v) CatSet_V(table);
    Cat(argc, argv, flags, table, optind);
  }
  return 0;
}
