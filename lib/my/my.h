/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Task 02
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_nbr_long(long nb);
int my_put_nbr_long_long(long long nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_putstr_alpha(char const *str);
int my_strlen(char const *str);
int my_strlengh(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int char_is_alphanum(char c);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strcasecmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *tab);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str);
char *verify_letter(char *str, int i);
char *verify_for_first(char *str);
char *get_nbr_str(char const *str, int *sign);
int verify_overflow(char *str, int *sign);
int check_str(char const *str, char const *to_find, int count);

#endif
