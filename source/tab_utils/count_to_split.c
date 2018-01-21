/*
** EPITECH PROJECT, 2018
** count_to_split
** File description:
** count_to_split
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

int count_to_split(char *cmd, char to_split)
{
	int c = 1;

	for (int i = 0; cmd[i]; i = i + 1)
		if (cmd[i] == to_split)
			c = c + 1;
	return (c);
}
