/*
** EPITECH PROJECT, 2018
** my_cd
** File description:
** my_cd
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

void my_cd(char *path, env_t **env)
{
	char buf[256];

	if (!verify_path(path, env))
		return;
	if (my_strcmp(path, "-") == 0) {
		chdir(my_getenv(*env, "OLDPWD"));
		remove_env(env, "OLDPWD");
		add_env_to_list(env, "OLDPWD", my_getenv(*env, "PWD"));
		remove_env(env, "PWD");
		add_env_to_list(env, "PWD", getcwd(buf, 256));
		return;
	}
	remove_env(env, "OLDPWD");
	add_env_to_list(env, "OLDPWD", getcwd(buf, 256));
	chdir(path);
	remove_env(env, "PWD");
	add_env_to_list(env, "PWD", getcwd(buf, 256));
}
