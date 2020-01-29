/*
** EPITECH PROJECT, 2019
** bsq .h
** File description:
** bsq.h
*/

#ifndef HBSQ
#define HBSQ

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#define UNUSED __attribute__((unused))
#define CONST __attribute__((const))
#define VOID __attribute__((noreturn))
#define STR char *__attribute__((__cleanup__(destroy_str)))
#define ARRAY char **__attribute__((__cleanup__(destroy_array)))
#define INTAB int **__attribute__((__cleanup__(destroy_intab)))

void destroy_intab(int ***array);
void destroy_array(char ***array);
int my_putstr(char const *str);
int min(int a, int b, int c);
int my_erre(char *buffer, int max, int res, int f);
int my_strlen(char const *str);
void find_biggest_square(int size, char **tab);
void destroy_str(char **str);
int my_getnbr(char const *str);

#endif /* !HBSQ */
