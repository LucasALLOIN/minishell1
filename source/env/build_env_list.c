/*
** EPITECH PROJECT, 2018
** build_env_list
** File description:
** build_env_list
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "get_next_line.h"
#include "my.h"
#include "main.h"

void build_env_list(env_t **head, char **env)
{
	int x = 0;
	int y = 0;
	env_t *new_node;
	env_t *last;

	while (env[y]) {
		new_node = malloc(sizeof(env_t) + 1);
		new_node->var = my_malloc(my_strlen(env[y]) + 1);
		while (env[y][x]) {
			new_node->var[x] = env[y][x];
			x = x + 1;
		}
		new_node->next = NULL;
		if (*head == NULL) {
			*head = new_node;
		} else
			last->next = new_node;
		last = new_node;
		x = 0;
		y = y + 1;
	}
}
