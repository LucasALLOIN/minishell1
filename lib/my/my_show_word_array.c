/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** Task 03
*/

int my_show_word_array(char * const *tab)
{
	int size = 0;
	int i = 0;

	while (tab[size] != 0)
		size = size + 1;
	while (i < size) {
		my_putstr(tab[i]);
		my_putchar('\n');
		i = i + 1;
	}
	return (0);
}
