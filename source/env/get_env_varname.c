/*
** EPITECH PROJECT, 2018
** get_env_varname
** File description:
** get_env_varname
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

char *get_env_varname(char *to_get)
{
	int i = get_env_varname_len(to_get);
	char *var = my_malloc(i + 1);

	for (int y = 0; y < i; var[y] = to_get[y], y = y + 1);
	return (var);
}
