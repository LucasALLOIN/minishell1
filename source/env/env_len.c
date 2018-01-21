/*
** EPITECH PROJECT, 2018
** env_len
** File description:
** env_len
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

int env_len(env_t *list)
{
	int i = 0;

	while (list != NULL) {
		list = list->next;
		i = i + 1;
	}
	return (i);
}
