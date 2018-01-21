/*
** EPITECH PROJECT, 2018
** tild_replacer
** File description:
** tild_replacer
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

void tild_replacer(env_t *env, char **arg)
{
	int i = 0;
	int ln = 0;
	char *r;

	while (arg[i]) {
		ln = my_strlen(arg[i]);
		if (arg[i][0] == '~') {
			r = malloc(my_strlen(my_getenv(env, "HOME")) + 1 + ln);
			my_strcpy(r, my_getenv(env, "HOME"));
			my_strcat(r, arg[i] + 1);
			free(arg[i]);
			arg[i] = r;
		}
		i = i + 1;
	}
}
