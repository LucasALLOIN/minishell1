/*
** EPITECH PROJECT, 2018
** remove_from_env
** File description:
** remove_from_env
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

void remove_from_env(env_t **head, char **arg)
{
	int i = 1;

	while (arg[i]) {
		if (!is_unset_valid(arg[i]))
			return;
		else
			remove_env(head, arg[i]);
		i = i + 1;
	}
}
