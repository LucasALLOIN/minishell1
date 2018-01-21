/*
** EPITECH PROJECT, 2018
** is_empty_setenv
** File description:
** is_empty_setenv
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

int is_empty_setenv(env_t **head, char **arg)
{
	if (tab_lengh(arg) == 1) {
		display_env(*head);
		return (1);
	}
	return (0);
}
