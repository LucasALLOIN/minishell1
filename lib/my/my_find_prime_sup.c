/*
** EPITECH PROJECT, 2017
** my_find_prime_sup
** File description:
** Cat
*/

int is_prime(int nb)
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

int my_find_prime_sup(int nb)
{
	int i = nb;

	while (1) {
		if (is_prime(i)) {
			return (i);
		} else {
			i = i + 1;
		}
	}
}
