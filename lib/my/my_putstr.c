/*
** EPITECH PROJECT, 2017
** my_put_str
** File description:
** Cat
*/

int my_putstr(char const *str)
{
	char *mystr;

	mystr = str;
	while (*mystr != '\0') {
		my_putchar(*mystr);
		mystr = mystr + 1;
	}
	return (0);
}
