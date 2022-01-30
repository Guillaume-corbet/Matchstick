/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** error
*/

#include "matchstick.h"

int verif_line(match_t *ma)
{
    if (ma->charac == -1)
        return (84);
    if (ma->lines_take > ma->lines) {
        my_printf("Error: this line is out of range\n");
        ma->good = 0;
    } else if (ma->stock[0] < 48 ||
    ma->stock[0] > 57) {
        my_printf("Error: invalid input (positive number expected)\n");
        ma->good = 0;
    } else if (ma->lines_take == 0) {
        my_printf("Error: this line is out of range\n");
        ma->good = 0;
    } else
        ma->good = 1;
    return (0);
}

int verif_match(match_t *ma)
{
    if (ma->charac == -1)
        return (84);
    if (ma->match_take > ma->take_max) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
        ma->take_max);
        ma->good = 0;
    } else if ((ma->stock[0] < 48 || ma->stock[0] > 57) && ma->p == 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        ma->good = 0;
    } else if (ma->match_take == 0) {
        my_printf("Error: you have to remove at least one match\n");
        ma->good = 0;
    } else if (ma->match_take > ma->match_left[ma->lines_take - 1]) {
        my_printf("Error: not enough matches on this line\n");
        ma->good = 0;
    } else
        ma->good = 1;
    return (0);
}
