#include "s21_grep.h"

int main(int argc, char *argv[]) {
  int count_files = 0;
  int flag_out = 0;
  AllFlags flags = {NULL,  0,     0,     false, false, false,
                    false, false, false, false, NULL,  0};
  if (argc == 1) {
    printf("usage: grep [OPTION]... PATTERNS [FILE]...\n");
    printf("Try 'grep --help' for more information.\n");
  } else {
    ReadFlags(argc, argv, &flags, &flag_out);
    count_files = checkPattern(&argc, &argv, optind, &flags);
    if (count_files != -1) Grep(argc, argv, &flags, count_files);
  }
  return 0;
}
