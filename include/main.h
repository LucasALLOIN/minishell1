/*
1;5002;0c** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#ifndef MAIN_H_
#define MAIN_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct s_env {
	char *var;
	struct s_env *next;
} env_t;

int is_next_space(char a, char b);
int is_space_first(char *str, int to_check);
char *my_strclear(char *str);
char *my_malloc(unsigned int nb);

#endif
