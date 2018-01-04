/*
** EPITECH PROJECT, 2017
** my_str_isupper
** File description:
** Task 13
*/

int my_strlengh(char const *str);

int my_str_isupper(char const *str)
{
	int size = my_strlengh(str);
	int i = 0;
	int occ = 0;

	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z')
			occ = occ + 1;
		i = i + 1;
	}
	if (size == occ) {
		return (1);
	}
	return (0);
}
