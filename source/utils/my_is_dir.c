/*
** EPITECH PROJECT, 2018
** my_is_dir
** File description:
** my_is_dir
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

int my_is_dir(char *good_path)
{
	struct stat statbuf;

	if (good_path == NULL)
		return (0);
	if (stat(good_path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}
