/*
** EPITECH PROJECT, 2019
** second file
** File description:
** bsq.c
*/

#include "bsq.h"

char **malloc_fonction(char **tab, int size, char *buffer)
{
    int len = 0;
    int r = 0;

    for (int i = 0; r != 2; i++)
        (buffer[i] == '\n') ? (r == 0) ? (r++, len = 0) : (r++) : (len += 1);
    tab = malloc(sizeof(char *) * (size + 2));
    tab[size] = NULL;
    for (int i = 0; i != size + 1; i++)
        tab[i] = malloc(sizeof(char) * (len + 1));
    return (tab);
}

char **parsing(char **tab, char *str, UNUSED struct stat sb, UNUSED int size)
{
    int x = 0;
    int y = 0;

    for (int pos = 0; str[pos] != '\0'; pos++)
    {
        (str[pos] == '\n') ? (tab[y][x] = '\0') : 0;
        (str[pos] != '\n') ? (tab[y][x] = str[pos], x++) : (y++, x = 0);
    }
    tab[y] = NULL;
    return (tab);
}

int my_err(char *buffer, int size)
{
    int res = 0;
    int stat = 0;
    int max = 0;
    int nb = 0;
    for (int f = 0; buffer[f] != '\0'; f++, nb++) {
        if (buffer[f] == '\n') {
            res++;
            nb = 0;
            }
        if (my_erre(buffer, max, nb, f) == 1) {
            return (84);
        }
        if (res  == 1 && stat == 0 && buffer[f + 1] == '\n') {
            stat = 1;
            max = nb;
        }
    }
    if (res != (size + 1))
        return (84);
    return (0);
}

int second_part(struct stat sb, char **av)
{
    STR buffer = malloc(sizeof(char) * (sb.st_size + 1));
    int fd;
    int size;
    ARRAY tab = NULL;

    if ((fd = open(av[1], O_RDONLY)) == -1 || sb.st_size == 0)
        return (84);
    if ((read(fd, buffer, sb.st_size)) == -1)
        return (84);
    buffer[sb.st_size] = '\0';
    size = my_getnbr(buffer);
    if (my_err(buffer, size) == 84)
        return (84);
    tab = malloc_fonction(tab, size, buffer);
    tab = parsing(tab, buffer, sb, size);
    find_biggest_square(size, tab);
    close(fd);
    return (0);
}

int main(int ac, char **av)
{
    struct stat sb;
    int status;
    if (ac != 2 || av[1] == NULL)
        return (84);
    lstat(av[1], &sb);
    status = second_part(sb, av);
    return (status);
}