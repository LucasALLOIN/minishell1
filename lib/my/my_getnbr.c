/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** Task 05
*/

char *get_nbr_str(char const *str, int *sign)
{
	int i = 0;
	int neg = 0;
	int y = 0;
	char *s = str;

	for (i = 0;str[i] == '+' || str[i] == '-'; i = i + 1) {
		if (str[i] ==  '-')
			neg = neg + 1;
	}
	if (neg % 2 != 0)
		*sign = -1;
	str = str + i;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		i = i + 1;
	while (y < i) {
		s[y] = str[y];
		y = y + 1;
	}
	s[i] = '\0';
	return (s);
}

int verify_overflow(char *str, int *sign)
{
	int i = 0;
	char *max = "2147483648";

	if (my_strlen(str) > 10)
		return (0);
	else if (my_strlen(str) <= 9)
		return (1);
	if (*sign == 1)
		max = "2147483647";
	while (str[i] != '\0') {
		if (str[i] < max[i])
			return (1);
		if (str[i] == max[i])
			i = i + 1;
		if (str[i] > max[i])
			return (0);
	}
	return (1);
}

int my_getnbr(char const *str)
{
	int sign = 1;
	int i = 0;
	char *nbr;
	int nbr_final = 0;

	nbr = get_nbr_str(str, &sign);
	if (!verify_overflow(str, &sign))
		return (0);
	while (nbr[i] != '\0') {
		nbr_final = nbr_final * 10;
		nbr_final = nbr_final + (nbr[i] - '0');
		i = i + 1;
	}
	return (nbr_final * sign);
}
