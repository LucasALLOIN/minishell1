/*
** EPITECH PROJECT, 2018
** has_slash
** File description:
** has_slash
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

int has_slash(char *cmd)
{
	int i = 0;

	while (cmd[i]) {
		if (cmd[i] == '/')
			return (1);
		i = i + 1;
	}
	return (0);
}
