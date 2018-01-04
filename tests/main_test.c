/*
** EPITECH PROJECT, 2018
** Project mysh Testing
** File description:
** Unit Testing Project mysh
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "main.h"

void main_redirect_stdout(void)
{
	cr_redirect_stdout();
}

Test(mysh, Return_Value_Test)
{
	cr_assert_eq("Function to test()", "Int Output..");
}

Test(mysh, Stdout_Value_Test, .init = main_redirect_stdout)
{
	cr_assert_stdout_eq_str("Str Output..");
}
