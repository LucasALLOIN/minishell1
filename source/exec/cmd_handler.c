/*
** EPITECH PROJECT, 2018
** cmd_handler
** File description:
** cmd_handler
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

void cmd_handler(char *good_path, char **arg, env_t **env)
{
	if (good_path != NULL && !my_is_dir(good_path))
		launch_programm(good_path, arg, *env);
	else if (my_is_dir(good_path)) {
		my_puterror(arg[0]);
		my_puterror(": Permission denied.\n");
	} else {
		my_puterror(arg[0]);
		my_puterror(": Command not found.\n");
	}
}
