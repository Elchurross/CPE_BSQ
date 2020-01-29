/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** test main for criterion
*/

#include "bsq.h"

int my_bsq(int ac, char **av)
{
    struct stat sb;
    if (ac != 2)
        return (84);
    lstat(av[1], &sb);
    char buffer[sb.st_size + 1];
    int fd = open(av[1], O_RDONLY);
    read(fd, buffer, sb.st_size);
    return (0);
}