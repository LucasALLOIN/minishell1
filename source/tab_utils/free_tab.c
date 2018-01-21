/*
** EPITECH PROJECT, 2018
** free_tab
** File description:
** free_tab
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

void free_tab(char **tab)
{
	int i = 0;

	if (tab == NULL)
		return;
	for (i = 0; tab[i] != 0; i = i + 1)
		free(tab[i]);
	free(tab);
}
