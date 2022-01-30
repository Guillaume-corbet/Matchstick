/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_linel
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef READ_SIZE
#define READ_SIZE (1)
#endif /* !READ_SIZE */

#define BEGIN_GTL       \
char *buf;      \
static char *buffer;        \
char *tmp;      \
static int i = 0;       \
int b = 0;      \
int count = 1;      \
static int a = -42;

#define END_GTL     \
i = i + 1;      \
buf[b] = '\0';

#define UP_GTL      \
buf[b] = buffer[i];     \
b = b + 1;      \
i = i + 1;

#define UPGRADE_GTL     \
count = count + 1;      \
tmp = malloc(sizeof(char) * READ_SIZE * count);     \
my_strcpy(tmp, buf);        \
free(buf);      \
buf = malloc(sizeof(char) * READ_SIZE * count);     \
my_strcpy(buf, tmp);        \
free(tmp);      \
a = read(fd, buffer, READ_SIZE);        \
i = 0;

#define ZERO_GTL        \
free(buffer);       \
buffer = malloc(sizeof(char) * READ_SIZE);      \
a = read(fd, buffer, READ_SIZE);

#endif /* !GET_NEXT_LINE_H_ */
