/*
** EPITECH PROJECT, 2018
** modifie_env_var
** File description:
** modifie_env_var
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

void modifie_env_var(env_t *env, char **to_add, int empty)
{
	env_t *to_modifie;
	int m_val;
	char *final;

	m_val = my_strlen(to_add[1]) + my_strlen((empty) ? "" : to_add[2]) + 1;
	final = my_malloc(m_val);
	while (env != NULL && to_modifie != NULL) {
		if (is_in_env_entry(env->var, to_add[1]))
			to_modifie = env;
		env = env->next;
	}
	my_strcat(final, to_add[1]);
	my_strcat(final, "=");
	my_strcat(final, (empty) ? "" : to_add[2]);
	free(to_modifie->var);
	to_modifie->var = final;
}
