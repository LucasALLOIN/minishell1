/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** Task 11
*/

int my_str_isnum(char const *str)
{
	int size = my_strlengh(str);
	int i = 0;
	int occ = 0;

	while (str[i] != '\0') {
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			occ = occ + 1;
		i = i + 1;
	}
	if (size == occ) {
		return (1);
	}
	return (0);
}
