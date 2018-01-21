/*
** EPITECH PROJECT, 2018
** remove_env
** File description:
** remove_env
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

void remove_env(env_t **head, char *arg)
{
	env_t *tmp = *head;
	env_t *last;

	if (tmp != NULL && is_in_env_entry(tmp->var, arg)) {
		*head = tmp->next;
		free(tmp);
		return;
	}
	while (tmp != NULL && !is_in_env_entry(tmp->var, arg)) {
		last = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return;
	last->next = tmp->next;
	free(tmp->var);
	free(tmp);
}
