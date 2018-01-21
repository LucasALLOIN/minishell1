/*
** EPITECH PROJECT, 2018
** minishell_loop
** File description:
** minishell_loop
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

void minishell_loop(char *s, env_t *l_env)
{
	while (s) {
		s = my_strclear(s);
		if (check_cmd(s))
			mysh(&l_env, s);
		my_putstr("$> ");
		free(s);
		s = get_next_line(0);
		if (s == NULL)
			my_putstr("exit\n");
	}
}
