/*
** EPITECH PROJECT, 2018
** is_env_valid
** File description:
** is_env_valid
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

int is_env_valid(char *to_verif)
{
	int i = 0;

	if (!((to_verif[0] >= 'a' && to_verif[0] <= 'z') || \
	(to_verif[0] >= 'A' && to_verif[0] <= 'Z'))) {
		my_puterror("setenv: Variable name must begin with a letter.");
		my_puterror("\n");
		return (0);
	}
	while (to_verif[i]) {
		if ((to_verif[i] >= 'a' && to_verif[i] <= 'z') || \
		(to_verif[i] >= 'A' && to_verif[i] <= 'Z') || \
		(to_verif[i] >= '0' && to_verif[i] <= '9'))
			i = i + 1;
		else {
			my_puterror("setenv: Variable name must ");
			my_puterror("contain alphanumeric characters.\n");
			return (0);
		}
	}
	return (1);
}
