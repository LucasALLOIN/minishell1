/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
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

int main(int argc, char *argv[], char **env)
{
	char *s;
	env_t *l_env = NULL;

	(void) argc;
	(void) argv;
	signal(SIGINT, &handler);
	build_env_list(&l_env, env);
	my_putstr("$> ");
	s = get_next_line(0);
	if (s == NULL)
		my_putstr("exit\n");
	minishell_loop(s, l_env);
	free_env(&l_env);
	return (0);
}
