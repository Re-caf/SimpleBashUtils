CC = gcc
C_FLAGS = -Wall -Werror -Wextra -std=c11

all: s21_cat

s21_cat: s21_cat.c s21_cat.h s21_cat_help.c
	$(CC) $(C_FLAGS) -o s21_cat s21_cat.c s21_cat_help.c

rebuild: clean s21_cat

clean:
	rm -f s21_cat