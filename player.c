/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** player
*/

#include "matchstick.h"

int player_one_check(match_t *ma)
{
    if (ma->good == 1) {
        my_printf("Matches: ");
        ma->charac = getline(&ma->stock, &ma->bufs, stdin);
        ma->match_take = my_getnbr(ma->stock);
        if (verif_match(ma) == 84)
            return (84);
    }
    return (0);
}

int player_one_verif_all(match_t *ma)
{
    ma->bufs = 3;

    my_printf("\nYour turn:\n");
    ma->good = 0;
    while (ma->good != 1) {
        my_printf("Line: ");
        ma->charac = getline(&ma->stock, &ma->bufs, stdin);
        ma->lines_take = my_getnbr(ma->stock);
        if (verif_line(ma) == 84)
            return (84);
        if (player_one_check(ma) == 84)
            return (84);
    }
    return (0);
}

int player_one(match_t *ma)
{
    if (player_one_verif_all(ma) == 84)
        return (84);
    ma->good = 0;
    ma->match_total = ma->match_total - ma->match_take;
    ma->match_left[ma->lines_take - 1] =
    ma->match_left[ma->lines_take - 1] - ma->match_take;
    my_printf("Player removed %d match(es) from line %d\n",
    ma->match_take, ma->lines_take);
    display_map(ma);
    free(ma->stock);
    if (ma->match_total == 0) {
        my_printf("You lost, too bad...\n");
        return (2);
    }
    return (0);
}