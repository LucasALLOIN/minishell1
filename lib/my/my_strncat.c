/*
** EPITECH PROJECT, 2017
** my_strncast
** File description:
** Task 03
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
	int i = 0;
	int d_lengh = my_strlen(dest);

	while (src[i] != '\0' && i < nb) {
		dest[d_lengh + i] = src[i];
		i = i + 1;
	}
	dest[d_lengh + i] = '\0';
	return (dest);
}
