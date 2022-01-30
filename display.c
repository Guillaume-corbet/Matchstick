/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** display
*/

#include "matchstick.h"

void put_space_second(match_t *ma)
{
    int a = 0;

    ma->space = ma->columns - ma->space_begin[ma->y] - ma->match_left[ma->y];
    while (ma->space != a) {
        my_putchar(' ');
        a = a + 1;
    }
}

void put_dif_lines(match_t *ma)
{
    ma->x = 0;
    while (ma->x < ma->columns + 2) {
        my_putchar('*');
        ma->x = ma->x + 1;
    }
    my_putchar('\n');
}

void display_corpse(match_t *ma)
{
    put_space_second(ma);
    my_putchar('*');
    my_putchar('\n');
    ma->x = 0;
    ma->y = ma->y + 1;
}

void display_map(match_t *ma)
{
    int a = 0;

    put_dif_lines(ma);
    ma->y = 0;
    while (ma->y != ma->lines) {
        my_putchar('*');
        a = 0;
        while (a != ma->space_begin[ma->y]) {
            my_putchar(' ');
            a = a + 1;
        }
        a = 0;
        while (a != ma->match_left[ma->y]) {
            my_putchar('|');
            a = a + 1;
        }
        display_corpse(ma);
    }
    put_dif_lines(ma);
}