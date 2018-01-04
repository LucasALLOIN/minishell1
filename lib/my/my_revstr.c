/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** Task 03
*/

int my_strlengh(char const *str)
{
	int count = 0;
	char *mystr;

	mystr = str;
	while (*mystr != '\0') {
		count = count + 1;
		mystr = mystr + 1;
	}
	return (count);
}

char *strcpy(char *dest, char const *src)
{
	int count = 0;

	while (src[count] != '\0') {
		dest[count] = src[count];
		count = count + 1;
	}
	dest[count] = '\0';
	return (dest);
}

char *my_revstr(char *str)
{
	int lengh = my_strlengh(str) - 1;
	char res[lengh];
	int count = 0;

	while (lengh > -1) {
		res[count] = str[lengh];
		count = count + 1;
		lengh = lengh - 1;
	}
	res[count] = '\0';
	return (strcpy(str, res));
}
