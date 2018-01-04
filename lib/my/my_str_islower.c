/*
** EPITECH PROJECT, 2017
** my_str_islower
** File description:
** Task 12
*/

int my_strlengh(char const *str);

int my_str_islower(char const *str)
{
	int size = my_strlengh(str);
	int i = 0;
	int occ = 0;

	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z')
			occ = occ + 1;
		i = i + 1;
	}
	if (size == occ) {
		return (1);
	}
	return (0);
}
