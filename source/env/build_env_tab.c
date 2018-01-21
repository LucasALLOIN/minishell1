/*
** EPITECH PROJECT, 2018
** build_env_tab
** File description:
** build_env_tab
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

char **build_env_tab(env_t *list)
{
	char **res = malloc(sizeof(char *) * (env_len(list) + 1));
	int i = 0;

	while (list != NULL) {
		res[i] = list->var;
		i = i + 1;
		list = list->next;
	}
	res[i] = 0;
	return (res);
}
