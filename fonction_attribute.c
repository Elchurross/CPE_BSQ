/*
** EPITECH PROJECT, 2019
** attribute define for free
** File description:
** test
*/

#include "bsq.h"

void destroy_intab(int ***int_array)
{
    if (*int_array) {
        for (int index = 0; (*int_array)[index] != NULL; index++)
            free((*int_array)[index]);
        free(*int_array);
    }
}

void destroy_array(char ***array)
{
    if (*array) {
        for (size_t index = 0; (*array)[index]; index++)
            free((*array)[index]);
        free(*array);
    }
}

void destroy_str(char **str)
{
    if (*str)
        free(*str);
}

int min(int a, int b, int c)
{
    int m = a;
    if (m > b)
        m = b;
    if (m > c)
        m = c;
    return m;
}

int my_erre(char *buffer, int max, int res, int f)
{
    if (max != 0 && ( buffer[f+ 1] == '\n')) {
        if (max != res)
            return (1);
        }
    return (0);
}