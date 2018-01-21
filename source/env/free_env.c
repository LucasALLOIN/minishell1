/*
** EPITECH PROJECT, 2018
** free_env
** File description:
** free_env
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

void free_env(env_t **env)
{
	env_t *last = *env;

	while (*env != NULL) {
		free((*env)->var);
		last = *env;
		*env = (*env)->next;
		free(last);
	}
}
