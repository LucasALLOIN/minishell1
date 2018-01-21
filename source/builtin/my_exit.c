/*
** EPITECH PROJECT, 2018
** my_exit
** File description:
** my_exit
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

void my_exit(env_t **env, char **path, char **arg, char *cmd)
{
	int value = 0;

	if (tab_lengh(arg) > 2 || (tab_lengh(arg) != 1 \
	&& !my_str_isnum(arg[1]))) {
		my_puterror("exit: Expression Syntax.\n");
	} else {
		if (tab_lengh(arg) != 1)
			value = my_getnbr(arg[1]);
		free(cmd);
		free_env(env);
		free_tab(arg);
		free_tab(path);
		my_putstr("exit\n");
		exit(value % 256);
	}
}
