/*
** EPITECH PROJECT, 2018
** add_env_to_list_manager
** File description:
** add_env_to_list_manager
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

void add_env_to_list_manager(env_t **head, char **arg)
{
	if (is_empty_setenv(head, arg) || !is_env_valid(arg[1]))
		return;
	if (tab_lengh(arg) == 2) {
		if ((my_getenv(*head, arg[1])) != NULL) {
			modifie_env_var(*head, arg, 1);
		} else
			add_env_to_list(head, arg[1], "");
		return;
	}
	env_manager(head, arg);
}
