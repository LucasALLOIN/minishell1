/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** Task 01
*/

char *my_strcpy(char *dest, char const *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i = i + 1)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
