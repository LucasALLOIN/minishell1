/*
** EPITECH PROJECT, 2018
** print_error_on_exec
** File description:
** print_error_on_exec
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

void print_error_on_exec(int status)
{
	switch (status) {
	case 11:
	case 139:
		my_puterror("Segmentation fault\n");
		break;
	case 8:
	case 136:
		my_puterror("Floating exception\n");
	}
}
