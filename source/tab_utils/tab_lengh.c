/*
** EPITECH PROJECT, 2018
** tab_lengh
** File description:
** tab_lengh
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

int tab_lengh(char **tab)
{
	int i = 0;

	while (tab[i])
		i = i + 1;
	return (i);
}
