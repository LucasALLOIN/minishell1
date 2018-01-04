/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** Cat
*/

int my_put_nbr(int nb)
{
	if (nb >= 0) {
		if (nb > 9)
			my_put_nbr(nb / 10);
		my_putchar((nb % 10) + '0');
	} else {
		my_putchar('-');
		if (nb < -9)
			my_put_nbr((nb / 10) * -1);
		my_putchar(((nb % 10) * -1) + '0');
	}
	return (0);
}
