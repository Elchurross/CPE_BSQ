/*
** EPITECH PROJECT, 2019
** my lib
** File description:
** function lib
*/

#include "bsq.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}

int my_strlen(char const *str)
{
    int result;

    result = 0;
    while (str[result] != '\0') {
        result++;
    }
    return (result);
}

int ifneg(int calcul, int nombre)
{
    if (calcul == -1)
        nombre = -nombre;
    return (nombre);
}

int my_getnbr(char const *str)
{
    int calcul = 1;
    long nombre = 0;
    int i;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            if (str[i + 1] >= '0' && str[i + 1] <= '9')
                calcul = -1;
    for (int j = i; str[j] != '\0' && str[j] >= '0' && str[j] <= '9'; j++) {
        if (nombre > 2147483647 || nombre < -2147483648)
            return (0);
        nombre = nombre * 10 + str[j] - 48;
    }
    return (ifneg(calcul, nombre));
}