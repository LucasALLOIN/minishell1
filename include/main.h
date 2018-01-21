/*
** EPITECH PROJECT, 2018
** Project mysh
** File description:
** Header file
*/

#ifndef MAIN_H_
#define MAIN_H_
#include <stdlib.h>
#include <stdio.h>

typedef struct s_env {
	char *var;
	struct s_env *next;
} env_t;

void free_tab(char **tab);
void free_env(env_t **env);
void my_puterror(char *str);
int tab_lengh(char **tab);
char *get_var_name(char *var);
int is_in_env_entry(char *env, char *elem);
int is_in_env(env_t *env, char *elem);
char *my_getenv(env_t *env, char *elem);
char *my_get_full_env(env_t *env, char *elem);
char *my_malloc(unsigned int size);
void display_env(env_t *head);
int get_env_varname_len(char *to_get);
char *get_env_varname(char *to_get);
int is_env_valid(char *to_verif);
int is_in_env_for_add(env_t *env, char *to_add);
void modifie_env_var(env_t *env, char **to_add, int empty);
void add_env_to_list(env_t **head, char *to_add, char *val);
void remove_env(env_t **head, char *arg);
int is_empty_setenv(env_t **head, char **arg);
void env_manager(env_t **head, char **arg);
void add_env_to_list_manager(env_t **head, char **arg);
int is_unset_valid(char *to_rm);
void remove_from_env(env_t **head, char **arg);
void build_env_list(env_t **head, char **env);
int check_cmd(char *cmd);
void show_env(char **env);
void display_cd_error(char *path);
int verify_path(char *path, env_t **env);
void my_cd(char *path, env_t **env);
void my_exit(env_t **env, char **path, char **arg, char *cmd);
int is_exit(env_t **env, char **path, char **arg, char *cmd);
int is_env(env_t **env, char **arg);
int is_setenv(env_t **env, char **arg);
int is_unsetenv(env_t **env, char **arg);
int is_cd(env_t **env, char **arg);
int check_builtin(env_t **env, char **path, char **arg, char *cmd);
int count_to_split(char *cmd, char to_split);
char **my_str_to_array(char *cmd, char to_s);
int env_len(env_t *list);
char **build_env_tab(env_t *list);
int has_slash(char *cmd);
char *get_real_path(char **arg, char **path);
int is_forking(int val);
void print_error_on_exec(int status);
void display_error_on(char *path);
void launch_programm(char *good_path, char **arg, env_t *env);
void handler(int sig);
void tild_replacer(env_t *env, char **arg);
int my_is_dir(char *good_path);
void cmd_handler(char *good_path, char **arg, env_t **env);
void mysh(env_t **env, char *cmd);
void minishell_loop(char *s, env_t *l_env);
int is_next_space(char a, char b);
int is_space_first(char *str, int to_check);
char *my_strclear(char *str);
char *my_cat(char *result, int *x, int *z, char *buffer);
int verify(int fd, char *buffer, int *f_read, int *size);
int is_e(int z, int i, int *f_read, int size);
char *format_buffer(int *t, char *buffer, char *res);
char *get_next_line(int fd);

#endif
