/*
** EPITECH PROJECT, 2018
** get_env_varname_len
** File description:
** get_env_varname_len
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

int get_env_varname_len(char *to_get)
{
	int i = 0;

	while (to_get[i] != '=')
		i = i + 1;
	return (i);
}
