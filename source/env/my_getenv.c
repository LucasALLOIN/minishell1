/*
** EPITECH PROJECT, 2018
** my_getenv
** File description:
** my_getenv
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

char *my_getenv(env_t *env, char *elem)
{
	for (; env != NULL; env = env->next) {
		if (is_in_env_entry(env->var, elem)) {
			return (env->var + my_strlen(elem) + 1);
		}
	}
	return (NULL);
}
