/*
** EPITECH PROJECT, 2018
** handler
** File description:
** handler
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

void handler(int sig)
{
	(void) sig;
	signal(SIGINT, &handler);
	if (is_forking(2))
		my_putstr("\n");
	else
		my_putstr("\n$> ");
}
