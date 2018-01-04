/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** Task 01
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
	int size = my_strlen(src);
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * (size + 1));
	while (src[i] !=  '\0') {
		str[i] = src[i];
		i = i + 1;
	}
	str[i] = '\0';
	return (str);
}
