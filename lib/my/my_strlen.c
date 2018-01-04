/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** Lol
*/

int my_strlen(char const *str)
{
	int count = 0;

	while (str[count])
		count = count + 1;
	return (count);
}
