/*
** EPITECH PROJECT, 2018
** display_env
** File description:
** display_env
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

void display_env(env_t *head)
{
	while (head != NULL) {
		my_putstr(head->var);
		my_putchar('\n');
		head = head->next;
	}
}
