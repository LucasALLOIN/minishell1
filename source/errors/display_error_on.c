/*
** EPITECH PROJECT, 2018
** display_error_on
** File description:
** display_error_on
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

void display_error_on(char *path)
{
	switch (errno) {
	case ENOEXEC:
		my_puterror(path);
		my_puterror(": Exec format error. Wrong Architecture.\n");
		break;
	default:
		perror(path);
	}
}
