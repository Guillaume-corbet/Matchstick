/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** ia
*/

#include "matchstick.h"

void calcul_line_left(match_t *ma)
{
    int a = 0;

    ma->line_left = 0;
    while (a < ma->lines) {
        if (ma->match_left[a] > 0)
            ma->line_left = ma->line_left + 1;
        a = a + 1;
    }
}

void ia_two_last_line_second(match_t *ma, int a, int b)
{
    if (ma->match_left[a] == 1 && ma->match_left[b] <= ma->take_max
    && ma->match_left[b] > 1 && ma->yes == 0) {
        ma->lines_take = b + 1;
        ma->match_take = ma->match_left[b];
        ma->yes = 1;
    }
    if (ma->match_left[b] == 1 && ma->match_left[a] <= ma->take_max
    && ma->match_left[a] > 1 && ma->yes == 0) {
        ma->lines_take = a + 1;
        ma->match_take = ma->match_left[a];
        ma->yes = 1;
    }
    if (ma->match_left[b] > ma->match_left[a] && ma->yes == 0
    && (ma->match_left[b] - ma->match_left[a]) < ma->take_max) {
        ma->lines_take = b + 1;
        ma->match_take = ma->match_left[b] - ma->match_left[a];
        ma->yes = 1;
    }
}

void ia_two_last_line_first(match_t *ma, int a, int b)
{
    if (ma->match_left[a] > ma->match_left[b] && ma->yes == 0
    && (ma->match_left[a] - ma->match_left[b]) < ma->take_max) {
        ma->lines_take = a + 1;
        ma->match_take = ma->match_left[a] - ma->match_left[b];
        ma->yes = 1;
    }
    if (ma->yes == 0) {
        ma->lines_take = a + 1;
        ma->match_take = 1;
        ma->yes = 1;
    }
}

void ia_two_last_line(match_t *ma)
{
    int a = 0;
    int b = 0;

    ma->yes = 0;
    while (ma->match_left[a] == 0)
        a = a + 1;
    b = a;
    b = b + 1;
    while (ma->match_left[b] == 0)
        b = b + 1;
    ia_two_last_line_second(ma, a, b);
    ia_two_last_line_first(ma, a, b);
}

void ia_last_line(match_t *ma)
{
    int a = 0;

    while (ma->match_left[a] == 0)
        a = a + 1;
    ma->lines_take = a + 1;
    if (ma->match_left[a] == ma->take_max + 1)
        ma->match_take = ma->take_max;
    else if (ma->match_left[a] <= ma->take_max && ma->match_left[a] != 1)
        ma->match_take = ma->match_left[a] - 1;
    else {
        ma->match_take = 1;
    }
}