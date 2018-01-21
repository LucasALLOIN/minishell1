/*
** EPITECH PROJECT, 2018
** is_exit
** File description:
** is_exit
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

int is_exit(env_t **env, char **path, char **arg, char *cmd)
{
	if (my_strcmp(arg[0], "exit") == 0) {
		my_exit(env, path, arg, cmd);
		return (1);
	}
	return (0);
}
