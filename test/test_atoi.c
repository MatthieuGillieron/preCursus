/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:32:48 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:17:40 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void test_atoi(const char *str, int expected, int nbr_test, const char *name, int *is_valid)
{
    int result = ft_atoi(str);

    if (result != expected)
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: %d | obtenu: %d\n", nbr_test, name, expected, result);
        *is_valid = 0;
    }
    else
    {
        printf("Test %d (%s) \033[32m[PASSED]\033[0m\n", nbr_test, name);
    }
}

int main(void)
{
    int is_valid = 1;

    test_atoi("0", 0, 1, "Zero.", &is_valid);
    test_atoi("123", 123, 2, "PosNu", &is_valid);
    test_atoi("-123", -123, 3, "NegNu", &is_valid);
    test_atoi("2147483647", 2147483647, 4, "Max_i", &is_valid);
    test_atoi("-2147483648", -2147483648, 5, "Min_i", &is_valid);
    test_atoi("   42", 42, 6, "Pspac", &is_valid);
    test_atoi("   -42", -42, 7, "Nspac", &is_valid);
    test_atoi("+42", 42, 8, "Psign", &is_valid);
    test_atoi("42abc", 42, 9, "P-Dch", &is_valid);
    test_atoi("-42abc", -42, 10, "N-Dc", &is_valid);

    if (is_valid)
    {
        printf("\nft_atoi ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_atoi ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
