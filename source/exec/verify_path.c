/*
** EPITECH PROJECT, 2018
** verify_path
** File description:
** verify_path
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

int verify_path(char *path, env_t **env)
{
	char buf[256];
	DIR *dir;

	errno = 0;
	if (path == NULL) {
		remove_env(env, "OLDPWD");
		add_env_to_list(env, "OLDPWD", my_getenv(*env, "PWD"));
		chdir(my_getenv(*env, "HOME"));
		remove_env(env, "PWD");
		add_env_to_list(env, "PWD", getcwd(buf, 256));
		return (0);
	}
	dir = opendir(path);
	if (errno == 0 || my_strcmp(path, "-") == 0) {
		closedir(dir);
		return (1);
	}
	display_cd_error(path);
	closedir(dir);
	return (0);
}
