/*
** EPITECH PROJECT, 2017
** my_strcapitalize
** File description:
** Task09
*/

char *verify_letter(char *str, int i)
{
	if (str[i - 1] == '+' || str[i - 1] == ' ' || str[i - 1] == '-')
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	if (str[i - 1] >= 48 && str[i - 1] <= 57)
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	return (str[i]);
}

char *verify_for_first(char *str)
{
	if (str[0] >= 'a' && str[0] <= 'z') {
		str[0] = str[0] - 32;
	}
	return (str[0]);
}

char *my_strcapitalize(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (!(i == 0)) {
			str[i] = verify_letter(str, i);
		} else {
			str[i] = verify_for_first(str);
		}
		i = i + 1;
	}
	return (str);
}
