/*
** EPITECH PROJECT, 2018
** get_var_name
** File description:
** get_var_name
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

char *get_var_name(char *var)
{
	char *res;
	int i = 0;

	while (var[i] != '=')
		i = i + 1;
	res = malloc(i);
	for (int z = 0; z < i; z = z + 1)
		res[z] = var[z];
	return (res);
}
