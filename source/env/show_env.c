/*
** EPITECH PROJECT, 2018
** show_env
** File description:
** show_env
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

void show_env(char **env)
{
	int i = 0;

	while (env[i]) {
		my_putstr(env[i]);
		my_putchar('\n');
		i = i + 1;
	}
}
