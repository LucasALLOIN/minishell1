/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** Task 05
*/

static char my_to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i = i + 1;
        return (s1[i] - s2[i]);
}

int my_strcasecmp(char const *s1, char const *s2)
{
	int i = 0;
	int x = 0;
        char *str1 = malloc(my_strlen(s1) + 1);
        char *str2 = malloc(my_strlen(s1) + 1);

        while (s1[i]) {
                str1[i] = my_to_lower(s1[i]);
		i = i +	1;
        }
        i = 0;
        while (s2[i]) {
                str2[i] = my_to_lower(s2[i]);
                i = i +	1;
        }
	x = my_strcmp(str1, str2);
	free(str1);
	free(str2);
        return (x);
}
