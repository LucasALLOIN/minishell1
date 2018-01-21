/*
** EPITECH PROJECT, 2018
** check_cmd
** File description:
** check_cmd
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

int check_cmd(char *cmd)
{
	if (cmd[0] == 0)
		return (0);
	return (1);
}
