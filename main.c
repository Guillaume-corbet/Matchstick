/*
** EPITECH PROJECT, 2019
** CPE_ma->matchstick_2018
** File description:
** main
*/

#include "matchstick.h"

char *get_next_line(int fd)
{
    BEGIN_GTL;
    if (a != -42) {
        free(buf);
    }
    buf = malloc(sizeof(char) * READ_SIZE);
    if (i == 0)
        ZERO_GTL;
    while (buffer[i] != '\n' && buffer[i] != '\0') {
        if (a == 0 || a == -1) {
            return (NULL);
        }
        UP_GTL;
        if (i == READ_SIZE) {
            UPGRADE_GTL;
        }
    }
    END_GTL;
    if (fd == 0)
        i = 0;
    return (buf);
}

int random_nb(int min, int max)
{
    srand(time(NULL));
    return rand()%(max-min+1) + min;
}

int main(int argc, char **argv)
{
    match_t *ma;
    int a = 0;

    srandom(time(0));
    if ((ma = malloc(sizeof(match_t))) == NULL)
        return (84);
    if (init(argc, argv, ma) == 84)
        return (84);
    if (init_matches(ma) == 84)
        return (84);
    display_map(ma);
    while (1) {
        a = player_one(ma);
        if (a == 2)
            return (2);
        else if (a == 84)
            return (0);
        if (player_two(ma) == 1)
            return (1);
    }
    return (0);
}