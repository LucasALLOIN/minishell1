/*
** EPITECH PROJECT, 2018
** is_unsetenv
** File description:
** is_unsetenv
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

int is_unsetenv(env_t **env, char **arg)
{
	if (my_strcmp(arg[0], "unsetenv") == 0) {
		remove_from_env(env, arg);
		return (1);
	}
	return (0);
}
