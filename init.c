/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** init
*/

#include "matchstick.h"

int init_malloc(char **argv, match_t *ma)
{
    if ((ma->stock = malloc(sizeof(char) * 10)) == NULL)
        return (84);
    if ((ma->match_left = malloc(sizeof(int) * ma->lines)) == NULL)
        return (84);
    if ((ma->space_begin = malloc(sizeof(int) * ma->lines)) == NULL)
        return (84);
    return (0);
}

int init(int argc, char **argv, match_t *ma)
{
    if (argc != 3)
        return (84);
    ma->x = 0;
    ma->y = 0;
    ma->count = 0;
    ma->count_match = 0;
    ma->match_total = 0;
    ma->a = 0;
    ma->space = 0;
    ma->columns = 1;
    if ((ma->lines = my_getnbr(argv[1])) <= 0 || ma->lines > 100)
        return (84);
    if ((ma->take_max = my_getnbr(argv[2])) <= 0)
        return (84);
    ma->columns = ma->columns + (ma->lines * 2) - 2;
    if (init_malloc(argv, ma) == 84)
        return (84);
    ma->ia_take = ma->take_max;
    return (0);
}

int init_matches(match_t *ma)
{
    ma->y = 0;
    while (ma->count < ma->lines) {
        ma->count_match = 1 + (2 * ma->count);
        ma->match_left[ma->count] = ma->count_match;
        ma->match_total = ma->match_total + ma->match_left[ma->count];
        ma->count = ma->count + 1;
    }
    ma->match_left[ma->count] == 0;
    while (ma->y != ma->lines) {
        ma->space = (ma->columns - ma->match_left[ma->y]) / 2;
        ma->space_begin[ma->y] = ma->space;
        ma->y = ma->y + 1;
    }
    return (0);
}