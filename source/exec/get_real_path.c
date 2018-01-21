/*
** EPITECH PROJECT, 2018
** get_real_path
** File description:
** get_real_path
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

char *get_real_path(char **arg, char **path)
{
	char *res;
	int len = my_strlen(arg[0]);

	if (path == NULL)
		return (NULL);
	if (has_slash(arg[0])) {
		res = my_malloc(len + 1);
		my_strcpy(res, arg[0]);
		return ((access(res, X_OK) == 0) ? res : NULL);
	}
	for (int i = 0; path[i]; i = i + 1) {
		res = my_malloc(len + my_strlen(path[i]) + 2);
		my_strcat(res, path[i]);
		my_strcat(res, "/");
		my_strcat(res, arg[0]);
		if (access(res, X_OK) == 0)
			return (res);
		free(res);
	}
	return (NULL);
}
