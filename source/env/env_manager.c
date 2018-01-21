/*
** EPITECH PROJECT, 2018
** env_manager
** File description:
** env_manager
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

void env_manager(env_t **head, char **arg)
{
	if ((my_getenv(*head, arg[1])) != NULL) {
		modifie_env_var(*head, arg, 0);
	} else
		add_env_to_list(head, arg[1], arg[2]);
}
