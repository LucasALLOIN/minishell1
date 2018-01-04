/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** Task 04
*/

int my_strlengh(char const *str);

int check_str(char const *str, char const *to_find, int count)
{
	int tmp = 0;
	int lengh = my_strlengh(to_find);

	while (str[count] == to_find[tmp]) {
		tmp = tmp + 1;
		count = count + 1;
	}
	if (tmp != 0 && tmp == lengh)
		return (1);
	return (0);
}

char *my_strstr(char const *str, char const *to_find)
{
	int count = 0;

	while (str[count] != '\0') {
		if (check_str(str, to_find, count))
			return (str + count);
		count = count + 1;
	}
	return ('\0');
}
