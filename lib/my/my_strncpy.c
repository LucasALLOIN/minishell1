/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** Task 02
*/

int my_strlengh(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
	int count = 0;

	while (count < n && src[count] != '\0') {
		dest[count] = src[count];
		count = count + 1;
	}
	while (count < n) {
		dest[count] = '\0';
		count = count + 1;
	}
	return (dest);
}
