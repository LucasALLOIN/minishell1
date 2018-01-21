/*
** EPITECH PROJECT, 2018
** is_in_env_entry
** File description:
** is_in_env_entry
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

int is_in_env_entry(char *env, char *elem)
{
	int i = 0;
	int env_l = 0;
	int elem_l = my_strlen(elem);

	while (env[env_l] != '=')
		env_l += 1;
	if (env_l != elem_l)
		return (0);
	while (i <= env_l - 1) {
		if (env[i] != elem[i])
			return (0);
		i = i + 1;
	}
	return (1);
}
