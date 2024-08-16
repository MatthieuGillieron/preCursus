/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:27:17 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:16:09 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

void test_memcmp(const void *s1, const void *s2, size_t n, int expected, int nbr_test, const char *name, int *is_valid)
{
    int result = ft_memcmp(s1, s2, n);

    if ((result < 0 && expected < 0) || (result > 0 && expected > 0) || (result == 0 && expected == 0))
    {
        printf("Test %d (%s) \033[32m[PASSED]\033[0m\n", nbr_test, name);
    }
    else
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: %d | obtenu: %d\n", nbr_test, name, expected, result);
        *is_valid = 0;
    }
}

int main(void)
{
    int is_valid = 1;

    char str1[] = "Hello, world!";
    char str2[] = "Hello, World!";
    char str3[] = "Hello, world!";
    char str4[] = "hello, world!";
    char str5[] = "";

	test_memcmp(str1, str2, 6, 0, 1, "Cmp06", &is_valid); // Compare first 6 characters of different strings
	test_memcmp(str1, str3, 6, 0, 2, "CmpId", &is_valid); // Compare first 6 characters of identical strings
	test_memcmp(str1, str4, 6, -1, 3, "CmpCs", &is_valid); // Compare first 6 characters of strings with different case
	test_memcmp(str1, str5, 6, 1, 4, "CmpNv", &is_valid); // Compare non-empty string with empty string
	test_memcmp(str1, str2, 3, 0, 5, "Cmp03", &is_valid); // Compare first 3 characters of different strings
	test_memcmp(str1, str2, 0, 0, 6, "Cmp00", &is_valid); // Compare strings with zero length

    if (is_valid)
    {
        printf("\nft_memcmp ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_memcmp ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
