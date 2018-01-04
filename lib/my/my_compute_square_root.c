/*
** EPITECH PROJECT, 2017
** my_compute_square_root
** File description:
** Cat
*/

int my_compute_square_root(int nb)
{
	int i = 0;

	while (i < nb/2) {
		if (i * i == nb) {
			return (i);
		}
		i = i + 1;
	}
	return (0);
}
