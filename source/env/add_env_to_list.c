/*
** EPITECH PROJECT, 2018
** add_env_to_list
** File description:
** add_env_to_list
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

void add_env_to_list(env_t **head, char *to_add, char *val)
{
	env_t *new_node = malloc(sizeof(env_t));
	env_t *last = *head;
	char *tmp = my_malloc(my_strlen(to_add) + my_strlen(val) + 2);

	new_node->var = my_malloc(my_strlen(to_add) + my_strlen(val) + 2);
	my_strcat(tmp, to_add);
	my_strcat(tmp, "=");
	my_strcat(tmp, val);
	my_strcpy(new_node->var, tmp);
	free(tmp);
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}
