/*
** EPITECH PROJECT, 2018
** is_cd
** File description:
** is_cd
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

int is_cd(env_t **env, char **arg)
{
	if (my_strcmp(arg[0], "cd") == 0) {
		my_cd(arg[1], env);
		return (1);
	}
	return (0);
}
