/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Main file.
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
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

void free_env(env_t **env)
{
	env_t *last = *env;
	
	while (*env != NULL) {
		free((*env)->var);
		last = *env;
		*env = (*env)->next;
		free(last);
	}
}

char *get_var_name(char *var)
{
	char *res;
	int i = 0;

	while (var[i] != '=')
		i = i + 1;
	res = malloc(i);
	for (int z = 0; z < i; z = z + 1)
		res[z] = var[z];
	return (res);
}

int is_in_env_entry(char *env, char *elem)
{
	int i = 0;
	int env_l = 0;
	int elem_l = my_strlen(elem);

	while (env[env_l] != '=')
		env_l += 1;
	if (env_l != elem_l)
		return (0);
	while (i <= env_l - 1) {
		if (env[i] != elem[i])
			return (0);
		i = i + 1;
	}
	return (1);
}

int is_in_env(env_t *env, char *elem)
{
	while (env != NULL) {
		if (is_in_env_entry(env->var, elem))
			return (1);
		env = env->next;
	}
	return (0);
}

char *my_getenv(env_t *env, char *elem)
{
	for (; env != NULL; env = env->next) {
		if (is_in_env_entry(env->var, elem)) {
			return (env->var + my_strlen(elem) + 1);
		}
	}
	return (NULL);
}

char *my_get_full_env(env_t *env, char *elem)
{
	for (; env != NULL; env = env->next) {
		if (is_in_env_entry(env->var, elem)) {
			return (env->var);
		}
	}
	return (NULL);
}

char *my_malloc(unsigned int size)
{
        char *mall = malloc(size);

        for (unsigned int i = 0; i < size; i = i + 1)
                mall[i] = '\0';
        return (mall);
}

void display_env(env_t *head)
{
	while (head != NULL) {
		my_putstr(head->var);
		my_putchar('\n');
		head = head->next;
	}
}

int get_env_varname_len(char *to_get)
{
	int i = 0;

	while (to_get[i] != '=')
		i = i + 1;
	return (i);
}

char *get_env_varname(char *to_get)
{
	int i = get_env_varname_len(to_get);
        char *var = my_malloc(i + 1);

        for (int y = 0; y < i; var[y] = to_get[y], y = y + 1);
	return (var);
}

int is_env_valid(char *to_verif)
{
	int i = 0;

	while (to_verif[i]) {
		if ((to_verif[i] >= 'a' && to_verif[i] <= 'z') || \
		(to_verif[i] >= 'A' && to_verif[i] <= 'Z') || \
		(to_verif[i] >= '0' && to_verif[i] <= '9'))
			i = i + 1;
		else
			return (0);
	}
	return (1);
}

int is_in_env_for_add(env_t *env, char *to_add)
{
	char *var = get_env_varname(to_add);

	while (env != NULL) {
		if (is_in_env_entry(env->var, var)) {
			free(var);
			return (1);
		}
		env = env->next;
	}
	free(var);
        return (0);
}

void modifie_env_var(env_t *env, char *to_add)
{
        env_t *to_modifie;
	char *var = get_env_varname(to_add);
	char *final = my_malloc(my_strlen(var) + my_strlen(to_add) + 1);

	while (env != NULL && to_modifie != NULL) {
		if (is_in_env_entry(env->var, var))
			to_modifie = env;
		env = env->next;
	}
        my_strcat(final, to_modifie->var);
	my_strcat(final, ":");
        my_strcat(final, to_add + my_strlen(var) + 1);
	free(to_modifie->var);
	to_modifie->var = final;
	free(var);
}

void add_env_to_list(env_t **head, char *to_add, char *val)
{
	env_t *new_node = malloc(sizeof(env_t));
	env_t *last = *head;
	char *tmp = my_malloc(my_strlen(to_add) + my_strlen(val) + 2);

	new_node->var = my_malloc(my_strlen(to_add) + my_strlen(val) + 2);
	my_strcat(tmp, to_add);
	my_strcat(tmp, "=");
	my_strcat(tmp, val);
	my_strcpy(new_node->var, tmp);
	free(tmp);
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void remove_env(env_t **head, char *arg)
{
	env_t *tmp = *head;
	env_t *last;

	if (tmp != NULL && is_in_env_entry(tmp->var, arg)) {
		*head = tmp->next;
		free(tmp);
		return;
	}
	while (tmp != NULL && !is_in_env_entry(tmp->var, arg)) {
		last = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return;
	last->next = tmp->next;
	free(tmp->var);
	free(tmp);
}

void add_env_to_list_manager(env_t **head, char **arg)
{
	if (!is_env_valid(arg[1]))
		return;
	if ((my_getenv(*head, arg[1])) != NULL) {
		remove_env(head, arg[1]);
		add_env_to_list(head, arg[1], arg[2]);
	} else
		add_env_to_list(head, arg[1], arg[2]);
}

int is_unset_valid(char *to_rm)
{
	int i = 0;

	while (to_rm[i]) {
		if (to_rm[i] == '=')
			return (0);
		i = i + 1;
	}
	if (i == 0)
		return (0);
	return (1);
}

void remove_from_env(env_t **head, char **arg)
{
	int i = 1;

	while (arg[i]) {
		if (!is_unset_valid(arg[i]))
			return;
		else
			remove_env(head, arg[i]);
		i = i + 1;
	}
}

void build_env_list(env_t **head, char **env)
{
	int x = 0;
	int y = 0;
	env_t *new_node;
	env_t *last;

	while (env[y]) {
		new_node = malloc(sizeof(env_t) + 1);
		new_node->var = my_malloc(my_strlen(env[y]) + 1);
		while (env[y][x]) {
			new_node->var[x] = env[y][x];
			x = x + 1;
		}
		new_node->next = NULL;
		if (*head == NULL) {
			*head = new_node;
		} else
			last->next = new_node;
		last = new_node;
		x = 0;
		y = y + 1;
	}
}

int check_cmd(char *cmd)
{
	if (cmd[0] == 0)
		return (0);
	return (1);
}

void show_env(char **env)
{
	int i = 0;

	while (env[i]) {
		my_putstr(env[i]);
		my_putchar('\n');
		i = i + 1;
	}
}

int verify_path(char *path, env_t **env)
{
	int result;
	char buf[256];

	if (path == NULL) {
		remove_env(env, "OLDPWD");
		add_env_to_list(env, "OLDPWD", my_getenv(*env, "PWD"));
		chdir(my_getenv(*env, "HOME"));
		remove_env(env, "PWD");
		add_env_to_list(env, "PWD", getcwd(buf, 256));
		return (0);
	}
	result = access(path, F_OK);
	if (result == 0 || my_strcmp(path, "-") == 0)
		return (1);
	return (0);
}

void my_cd(char *path, env_t **env)
{
	char buf[256];

	if (!verify_path(path, env))
		return;
	if (my_strcmp(path, "-") == 0) {
	        chdir(my_getenv(*env, "OLDPWD"));
		remove_env(env, "OLDPWD");
		add_env_to_list(env, "OLDPWD", my_getenv(*env, "PWD"));
		remove_env(env, "PWD");
		add_env_to_list(env, "PWD", getcwd(buf, 256));
		return;
	}
	remove_env(env, "OLDPWD");
	add_env_to_list(env, "OLDPWD", getcwd(buf, 256));
	chdir(path);
	remove_env(env, "PWD");
        add_env_to_list(env, "PWD", getcwd(buf, 256));
}

int check_builtin(env_t **env, char **path, char **arg, char *cmd)
{
	if (my_strcmp(arg[0], "env") == 0) {
		display_env(*env);
		return (1);
	} else if (my_strcmp(arg[0], "exit") == 0) {
		free(cmd);
		free_env(env);
		free_tab(arg);
		free_tab(path);
		my_putstr("exit\n");
		exit(0);
	} else if (my_strcmp(arg[0], "setenv") == 0) {
		add_env_to_list_manager(env, arg);
		return (1);
	} else if (my_strcmp(arg[0], "unsetenv") == 0) {
		remove_from_env(env, arg);
		return (1);
	} else if (my_strcmp(arg[0], "cd") == 0) {
		my_cd(arg[1], env);
		return (1);
	}
	return (0);
}

int count_to_split(char *cmd, char to_split)
{
	int c = 1;

	for (int i = 0; cmd[i]; i = i + 1)
		if (cmd[i] == to_split)
			c = c + 1;
	return (c);
}

char **my_str_to_array(char *cmd, char to_s)
{
	int z = 0;
	int y = 0;
	char **res = malloc(sizeof(char *) * (count_to_split(cmd, to_s) + 1));
	char *st = my_malloc(sizeof(char) * (my_strlen(cmd)) + 1);

        for (int i = 0; cmd[i]; i = i + 1) {
	        if (cmd[i] != to_s) {
			st[z] = cmd[i];
			z = z + 1;
		}
	        if (cmd[i] == to_s || !cmd[i + 1]) {
			z = 0;
			res[y] = st;
			st = my_malloc(sizeof(char *) * (my_strlen(cmd)) + 1);
			y = y + 1;
		}
	}
	res[y] = 0;
	free(st);
        return (res);
}

int env_len(env_t *list)
{
	int i = 0;

	while (list != NULL) {
		list = list->next;
		i = i + 1;
	}
	return (i);
}

char **build_env_tab(env_t *list)
{
	char **res = malloc(sizeof(char *) * (env_len(list) + 1));
	int i = 0;

	while (list != NULL) {
		res[i] = list->var;
		i = i + 1;
		list = list->next;
	}
	res[i] = 0;
	return (res);
}

char *get_real_path(char **arg, char **path)
{
	char *res;
	int len = my_strlen(arg[0]);

	if (path == NULL)
		return (NULL);
	if (arg[0][0] == '.' || arg[0][0] == '/') {
	        res = my_malloc(len + 1);
		my_strcpy(res, arg[0]);
		return (res);
	}
	for (int i = 0; path[i]; i = i + 1) {
		res = my_malloc(len + my_strlen(path[i]) + 2);
        	my_strcat(res, path[i]);
		my_strcat(res, "/");
		my_strcat(res, arg[0]);
		if (access(res, R_OK) == 0)
			return (res);
		free(res);
	}
	return (NULL);
}

int is_forking(int val)
{
	static int is_forking = 0;

	if (val != 2)
		is_forking = val;
	return (is_forking);
}

void launch_programm(char *good_path, char **arg, env_t *env)
{
	char **tab_env = build_env_tab(env);
	pid_t pid = fork();
	pid_t tpid;
	int status;
	
	if (pid == 0) {
		execve(good_path, arg, tab_env);
        } else {
		is_forking(1);
		tpid = wait(&status);
		while (tpid != pid)
			tpid = wait(&status);
		if (tpid == pid) {
			is_forking(0);
			free(tab_env);
			return;
		}
	}
}

void handler(int sig)
{
	(void) sig;
	signal(SIGINT, &handler);
	if (is_forking(2))
		my_putstr("\n");
	else
		my_putstr("\n$> ");
	
}

void tild_replacer(env_t *env, char **arg)
{
	int i = 0;
	int ln = 0;
	char *res;

	while (arg[i]) {
		ln = my_strlen(arg[i]);
		if (arg[i][0] == '~') {
			res = malloc(my_strlen(my_getenv(env, "HOME")) + 1 + ln);
			my_strcpy(res, my_getenv(env, "HOME"));
			my_strcat(res, arg[i] + 1);
			free(arg[i]);
			arg[i] = res;
		}
		i = i + 1;
	}
}

void mysh(env_t **env, char *cmd)
{
	char **arg = my_str_to_array(cmd, ' ');
	char **path = NULL;
	char *good_path;

	if (my_getenv(*env, "PATH") != NULL)
		path = my_str_to_array(my_getenv(*env, "PATH"), ':');
	tild_replacer(*env, arg);
	if (!check_builtin(env, path, arg, cmd)) {
		good_path = get_real_path(arg, path);
		if (good_path != NULL)
			launch_programm(good_path, arg, *env);
		else {
			my_putstr(arg[0]);
			my_putstr(": Command not found.\n");
		}
		free(good_path);
	}
	free_tab(arg);
	free_tab(path);
}

int main(int argc, char *argv[], char **env)
{
        char *s;
	env_t *l_env = NULL;

	(void) argc;
	(void) argv;
	signal(SIGINT, &handler);
	build_env_list(&l_env, env);
        my_putstr("$> ");
	s = get_next_line(0);
	if (s == NULL)
		my_putstr("exit\n");
	while (s) {
		s = my_strclear(s);
		if (check_cmd(s))
			mysh(&l_env, s);
		my_putstr("$> ");
        	free(s);
		s = get_next_line(0);
		if (s == NULL)
			my_putstr("exit\n");
	}
	free_env(&l_env);
        return (0);
}
