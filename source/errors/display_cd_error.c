/*
** EPITECH PROJECT, 2018
** display_cd_error
** File description:
** display_cd_error
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

void display_cd_error(char *path)
{
	my_puterror(path);
	switch (errno) {
	case EACCES:
		my_puterror(": Permission denied.\n");
		break;
	case ENOENT:
		my_puterror(": No such file or directory.\n");
		break;
	case ENOTDIR:
		my_puterror(": Not a directory.\n");
	}
}
