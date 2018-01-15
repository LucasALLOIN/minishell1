/*
** EPITECH PROJECT, 2018
** Project clean_str
** File description:
** Main file.
*/

#include <unistd.h>
#include "my.h"
#include "main.h"

int is_next_space(char a, char b)
{
	if (a == ' ' && (b == ' ' || b == 0 || b == '\t'))
		return (1);
	if (a == '\t' && (b == '\t' || b == 0 || b == ' '))
		return (1);
	return (0);
}

int is_space_first(char *str, int to_check)
{
	int i = 0;

	while (i <= to_check) {
		if (str[i] == ' ' || str[i] == '\t')
			i = i + 1;
		else
			return (1);
	}
	return (0);
}

char *my_strclear(char *str)
{
	int i = 0;
	int z = 0;
	int check = 0;
	char *res = my_malloc(my_strlen(str));

	while (str[i]) {
		check = is_space_first(str, i);
		if (is_next_space(str[i], str[i + 1]));
		else if (str[i] == '\t' && check) {
			res[z] = ' ';
			z += 1;
		} else if (check) {
			res[z] = str[i];
			z += 1;
		}
		i = i + 1;
	}
	free(str);
	return (res);
}
