/*
** EPITECH PROJECT, 2018
** is_in_env_for_add
** File description:
** is_in_env_for_add
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

int is_in_env_for_add(env_t *env, char *to_add)
{
	char *var = get_env_varname(to_add);

	while (env != NULL) {
		if (is_in_env_entry(env->var, var)) {
			free(var);
			return (1);
		}
		env = env->next;
	}
	free(var);
	return (0);
}
