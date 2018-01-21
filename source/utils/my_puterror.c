/*
** EPITECH PROJECT, 2018
** my_puterror
** File description:
** my_puterror
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

void my_puterror(char *str)
{
	write(2, str, my_strlen(str));
}
