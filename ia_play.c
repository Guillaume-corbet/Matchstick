/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** ia_play
*/

#include "matchstick.h"

void player_two_random(match_t *ma, int line)
{
    if (line <= ma->lines)
        ma->lines_take = line;
    if (ma->match_left[ma->lines_take - 1] <= 1 || ma->take_max <= 1)
        ma->match_take = 1;
    else if (ma->match_left[ma->lines_take - 1] > ma->take_max)
        ma->match_take = random_nb(1, ma->take_max);
    else
        ma->match_take = random_nb(1, ma->match_left[ma->lines_take - 1]);
    ma->p = 0;
}

void player_two_verif_all(match_t *ma)
{
    static int line = 0;

    ma->p = 1;
    my_printf("\nAI's turn...\n");
    calcul_line_left(ma);
    if (ma->line_left == 1) {
        ia_last_line(ma);
    } else if (ma->line_left == 2) {
        ia_two_last_line(ma);
    } else {
        while (ma->match_left[line - 1] == 0) {
            line = line + 1;
        }
        player_two_random(ma, line);
    }
}

int player_two(match_t *ma)
{
    player_two_verif_all(ma);
    ma->match_total = ma->match_total - ma->match_take;
    ma->match_left[ma->lines_take - 1] =
    ma->match_left[ma->lines_take - 1] - ma->match_take;
    my_printf("AI removed %d match(es) from line ", ma->match_take);
    my_put_nbr(ma->lines_take);
    my_putchar('\n');
    display_map(ma);
    if (ma->match_total == 0) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}