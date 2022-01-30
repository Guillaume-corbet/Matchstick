/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include "lib/my/my.h"
#include "lib/my_printf/my_printf.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct matchstick
{
    int yes;
    int p;
    int good;
    int take_max;
    int columns;
    int lines;
    int x;
    int y;
    int count;
    int count_match;
    int a;
    int space;
    int match_take;
    int lines_take;
    int change;
    int *match_left;
    int line_left;
    int match_total;
    int *space_begin;
    int ia_take;
    size_t charac;
    size_t bufs;
    char *stock;
}match_t;

int init_malloc(char **, match_t *);
int init(int, char **, match_t *);
int init_matches(match_t *);

void put_space_second(match_t *);
void put_dis_lines(match_t *);
void display_corpse(match_t *);
void display_map(match_t *);

int verif_line(match_t *);
int verif_match(match_t *);

int player_one_check(match_t *);
int player_one(match_t *);
int player_one_verif_all(match_t *);

void calcul_line_left(match_t *);
void ia_two_last_line_first(match_t *, int, int);
void ia_last_line(match_t *);
void ia_two_last_line(match_t *);

void player_two_random(match_t *, int);
int player_two(match_t *);
void player_two_verif_all(match_t *);

char *get_next_line(int);
int random_nb(int, int);

#endif /* !MATCHSTICK_H_ */
