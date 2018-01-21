/*
** EPITECH PROJECT, 2018
** is_unset_valid
** File description:
** is_unset_valid
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

int is_unset_valid(char *to_rm)
{
	int i = 0;

	while (to_rm[i]) {
		if (to_rm[i] == '=')
			return (0);
		i = i + 1;
	}
	if (i == 0)
		return (0);
	return (1);
}
