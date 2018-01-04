/*
** EPITECH PROJECT, 2017
** my_is_prime
** File description:
** Lol
*/

int my_is_prime(int nb)
{
	int i = 2;

	if (nb <= 1) {
		return (0);
	}
	while (i <= nb/2) {
		if (nb % i != 0) {
			i = i + 1;
		} else {
			return (0);
		}
	}
	return (1);
}
