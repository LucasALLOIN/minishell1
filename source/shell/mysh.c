/*
** EPITECH PROJECT, 2018
** mysh
** File description:
** mysh
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

void mysh(env_t **env, char *cmd)
{
	char **arg = my_str_to_array(cmd, ' ');
	char **path = NULL;
	char *good_path;

	if (my_getenv(*env, "PATH") != NULL)
		path = my_str_to_array(my_getenv(*env, "PATH"), ':');
	tild_replacer(*env, arg);
	if (!check_builtin(env, path, arg, cmd)) {
		good_path = get_real_path(arg, path);
		cmd_handler(good_path, arg, env);
		free(good_path);
	}
	free_tab(arg);
	free_tab(path);
}
