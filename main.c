/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** main fonction
*/

#include "bsq.h"

void print_my_map(char **tab, int max_of_s,  int max_i, int max_j)
{
    for (int i = max_i; i > max_i - max_of_s; i--)
        for (int j = max_j; j > max_j - max_of_s; j--)
            tab[i + 1][j] = 'x';
    for (int x = 1; tab[x] != NULL; x++) {
            write(1, tab[x], my_strlen(tab[x]));
            write(1, "\n", 1);
            }
}

int **plain_my_matrix(char **tab, int size, int **matrix, int C)
{
    for (int ind = 0; ind < size; ind++)
        matrix[ind] = malloc(sizeof(int) * C);
    for (int i = 0; i < size; i++)
        if (tab[i + 1][0] == '.')
            matrix[i][0] = 1;
        else
            matrix[i][0] = 0;
    for (int j = 0; j < C; j++)
        if (tab[1][j] == '.')
            matrix[0][j] = 1;
        else
            matrix[0][j] = 0;
    return (matrix);
}

int **next_biggest(int i, int j, int **t, char **tab)
{
    if (tab[i + 1][j] == '.')
        t[i][j] = min(t[i][j - 1], t[i - 1][j], t[i - 1][j - 1]) + 1;
    else
        t[i][j] = 0;
    return (t);
}

void next_next_biggest(int *max_of_s, int **matrix, int *max_j, int *max_i, \
int  i, int  j)
{
    if (*max_of_s < matrix[i][j]) {
        *max_of_s = matrix[i][j];
        *max_i = i;
        *max_j = j;
        }
}

void find_biggest_square(int size, char **tab)
{
    INTAB matrix;
    int max_of_s;
    int max_i = 0;
    int max_j = 0;
    int C = my_strlen(tab[1]);
    matrix = malloc(sizeof(int *) * (size + 1));
    matrix[size] = NULL;
    matrix = plain_my_matrix(tab, size, matrix, C);
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < C; j++) {
            matrix = next_biggest(i, j, matrix, tab);
        }
    }
    max_of_s = matrix[0][0];
    for (int i = 0; i < size; i++) {
        for ( int j = 0; j < C; j++) {
            next_next_biggest(&max_of_s, matrix, &max_j, &max_i, i, j);
        }
    }
    print_my_map(tab, max_of_s, max_i, max_j);
}
