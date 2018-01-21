/*
** EPITECH PROJECT, 2018
** is_setenv
** File description:
** is_setenv
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

int is_setenv(env_t **env, char **arg)
{
	if (my_strcmp(arg[0], "setenv") == 0) {
		add_env_to_list_manager(env, arg);
		return (1);
	}
	return (0);
}
