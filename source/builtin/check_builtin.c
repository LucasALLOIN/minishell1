/*
** EPITECH PROJECT, 2018
** check_builtin
** File description:
** check_builtin
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

int check_builtin(env_t **env, char **path, char **arg, char *cmd)
{
	if (is_exit(env, path, arg, cmd) || is_env(env, arg) \
	|| is_setenv(env, arg) || is_unsetenv(env, arg) \
	|| is_cd(env, arg))
		return (1);
	return (0);
}
