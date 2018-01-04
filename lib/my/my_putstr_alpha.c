/*
** EPITECH PROJECT, 2017
** my_put_str
** File description:
** Cat
*/

static my_char_is_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if ((c >= 'a' && c <= 'z') || c == ' ')
		return (1);
	return (0);
}

int my_putstr_alpha(char const *str)
{
	int i = 0;

	while (str[i]) {
		if (my_char_is_alpha(str[i]))
			my_putchar(str[i]);
		i = i + 1;
	}
	return (0);
}
