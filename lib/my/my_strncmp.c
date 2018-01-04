/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** Task 06
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int cou = 0;

	while (s1 != '\0' && s2 != '\0' && s1[cou] == s2[cou] && cou < n) {
		cou = cou + 1;
	}
	if (cou == n)
		return (0);
	return (s1[cou] - s2[cou]);
}
