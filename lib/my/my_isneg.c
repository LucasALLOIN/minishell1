/*
** EPITECH PROJECT, 2017
** my_isneg
** File description:
** A function that displays either N or P if the number is positif or negatif
*/

int my_isneg(int n)
{
	if (n < 0) {
		my_putchar('N');
	} else {
		my_putchar('P');
	}
	return (0);
}
