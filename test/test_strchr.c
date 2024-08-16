/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:05:56 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:23:16 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/libft.h"
#include <stdio.h>

void test_strchr(const char *s, int c, const char *expected, int test_num, const char *test_name, int *passed_tests)
{
    char *result = ft_strchr(s, c);

    if (result != expected)
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m: attendu '%s', obtenu '%s' ❌\n", test_num, test_name, expected ? expected : "NULL", result ? result : "NULL");
        *passed_tests = 0;
    }
    else
    {
        printf("Test %d (%s) \033[32m[PASSED]\033[0m\n", test_num, test_name);
    }
}

int main(void)
{
    int passed_tests = 1;

    char str1[] = "Hello, world!";
	test_strchr(str1, 'w', str1 + 7, 1, "FindW", &passed_tests); // Trouver 'w' dans la chaîne
	test_strchr(str1, 'z', NULL, 2, "FindZ", &passed_tests); // Trouver 'z' dans la chaîne (non présent)
	test_strchr(str1, 'H', str1, 3, "FindH", &passed_tests); // Trouver 'H' dans la chaîne
	test_strchr(str1, ',', str1 + 5, 4, "Find,", &passed_tests); // Trouver ',' dans la chaîne
	test_strchr(str1, 'o', str1 + 4, 5, "FindO", &passed_tests); // Trouver le premier 'o' dans la chaîne
	test_strchr(str1, '!', str1 + 12, 6, "Find!", &passed_tests); // Trouver '!' dans la chaîne
	test_strchr(str1, '\0', str1 + 13, 7, "Find0", &passed_tests); // Trouver le caractère nul

    if (passed_tests)
    {
        printf("ft_strchr ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("ft_strchr ❌\n");
		printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
