/*
** EPITECH PROJECT, 2018
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

#endif
