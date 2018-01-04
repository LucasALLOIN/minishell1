/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *my_cat(char *result, int *x, int *z, char *buffer)
{
	char *res = malloc(READ_SIZE * (x[1] + 1) + 1);
	int y = 0;

	x[1] += 1;
	for (int i = 0; i < READ_SIZE * x[1]; res[i] = 0, i = i + 1);
	for (; result[y]; res[y] = result[y], y = y + 1);
	*z = y - 1;
	free(result);
	for (int y = 0; buffer[y]; buffer[y] = 0, y = y + 1);
	x[0] = 0;
	return (res);
}

int verify_start_or_end(int fd, char *buffer, int *f_read, int *size)
{
	if (*f_read == 0) {
		*size = read(fd, buffer, READ_SIZE);
		*f_read = 1;
	} else if (*f_read == 2)
		return (1);
	return (0);
}

int is_end(int z, int i, int *f_read, int size)
{
	if (z == -1 && i == 0 && size == 0) {
		*f_read = 2;
		return (1);
	} else if (i == 0 && size == 0) {
		*f_read = 2;
		return (2);
	}
	return (0);
}

char *format_buffer(int *t, char *buffer, char *res)
{
	t[0] = t[0] + 1;
	for (t[1] = 0; buffer[t[0]]; buffer[t[1]] = buffer[t[0]], \
	t[1] = t[1] + 1, t[0] = t[0] + 1);
	for (; buffer[t[1]]; buffer[t[1]] = 0, t[1] = t[1] + 1);
	return (res);
}

char *get_next_line(int fd)
{
	static char buffer[READ_SIZE + 1];
	char *res = malloc(READ_SIZE + 1);
	int t[2] = {0, 1};
	static int arr[2] = {0, -50};

	if (verify_start_or_end(fd, buffer, &arr[0], &arr[1]))
		return (NULL);
	for (int g = 0; g < READ_SIZE; res[g] = 0, g = g + 1);
	for (int z = 0; buffer[t[0]] != '\n'; z = z + 1) {
		res[z] = buffer[t[0]];
		t[0] = t[0] + 1;
		if (buffer[t[0]] == '\0' && arr[1] != 0) {
			res = my_cat(res, t, &z, buffer);
			arr[1] = read(fd, buffer, READ_SIZE);
		}
		if (is_end(z, t[0], &arr[0], arr[1]) == 1)
			return (NULL);
		else if (is_end(z, t[0], &arr[0], arr[1]) == 2)
			return (res);
	}
	return (format_buffer(t, buffer, res));
}
