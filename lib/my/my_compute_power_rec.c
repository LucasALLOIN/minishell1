/*
** EPITECH PROJECT, 2017
** my_compute_power_rec
** File description:
** Lol
*/

int my_compute_power_rec(int nb, int p)
{
	int nbr;

	if (p == 0) {
		return (1);
	}
	if (p < 0) {
		return (0);
	}
	if (p != 1) {
		nbr = my_compute_power_rec(nb, p - 1) * nb;
	} else {
		return (nb);
	}
}
