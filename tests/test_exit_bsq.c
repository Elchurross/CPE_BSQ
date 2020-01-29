/*
** EPITECH PROJECT, 2019
** test criterion
** File description:
** test bsq project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_bsq(int ac, char **av);

Test(errors, exit_code)
{
    cr_assert_eq(my_bsq(1, NULL), 84);
}