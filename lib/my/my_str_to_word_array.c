/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** Task 04
*/

#include <stdlib.h>

int char_is_alphanum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char **my_str_to_word_array(char const *str)
{
        char **dest = malloc(sizeof(char *) * (my_strlen(str) + 1));
	char *st = malloc(sizeof(char *) * (my_strlen(str) + 1));
	int tab = 0;
	int z = 0;

        for (int i = 0; str[i] != '\0'; i = i + 1) {
		if (char_is_alphanum(str[i])) {
			st[z] = str[i];
			z = z + 1;
		}
		if ((!char_is_alphanum(str[i])) || str[i + 1] == '\0') {
			st[z] = '\0';
			z = 0;
			dest[tab] = my_strdup(st);
			tab = tab + 1;
		}
	}
	free(st);
	dest[tab] = 0;
	return (dest);
}
