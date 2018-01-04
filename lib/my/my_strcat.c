/*
** EPITECH PROJECT, 2017
** my_strcast
** File description:
** Task 02
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, const char *src)
{
	int dest_len = my_strlen(dest);
	int i = 0;

	for (; src[i] != '\0'; i = i + 1)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return (dest);
}
