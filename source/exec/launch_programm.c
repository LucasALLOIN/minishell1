/*
** EPITECH PROJECT, 2018
** launch_programm
** File description:
** launch_programm
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

void launch_programm(char *good_path, char **arg, env_t *env)
{
	char **tab_env = build_env_tab(env);
	pid_t pid = fork();
	pid_t tpid;
	int status;

	if (pid == 0) {
		if (execve(good_path, arg, tab_env) == -1)
			display_error_on(good_path);
	} else {
		is_forking(1);
		tpid = wait(&status);
		while (tpid != pid)
			tpid = wait(&status);
		if (tpid == pid) {
			is_forking(0);
			print_error_on_exec(status);
			free(tab_env);
			return;
		}
	}
}
