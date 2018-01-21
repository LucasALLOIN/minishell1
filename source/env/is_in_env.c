/*
** EPITECH PROJECT, 2018
** is_in_env
** File description:
** is_in_env
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

int is_in_env(env_t *env, char *elem)
{
	while (env != NULL) {
		if (is_in_env_entry(env->var, elem))
			return (1);
		env = env->next;
	}
	return (0);
}
