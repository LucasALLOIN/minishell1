/*
** EPITECH PROJECT, 2018
** my_malloc
** File description:
** my_malloc
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

char *my_malloc(unsigned int size)
{
	char *mall = malloc(size);

	for (unsigned int i = 0; i < size; i = i + 1)
		mall[i] = '\0';
	return (mall);
}
