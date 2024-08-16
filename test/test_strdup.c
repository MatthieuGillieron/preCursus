/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:41:09 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 22:42:05 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

void test_strdup(const char *str, const char *expected, int nbr_test, const char *name, int *is_valid)
{
    char *result = ft_strdup(str);

    if (result == NULL || strcmp(result, expected) != 0)
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m attendu: '%s' | obtenu: '%s'\n", nbr_test, name, expected, result ? result : "NULL");
        *is_valid = 0;
    }
    else
    {
        printf("Test %d (%s) \033[32m[PASSED]\033[0m\n", nbr_test, name);
    }
    free(result);
}

int main(void)
{
    int is_valid = 1;

    test_strdup("Hello, world!", "Hello, world!", 1, "Dupli", &is_valid);
    test_strdup("", "", 2, "Empty", &is_valid);
    test_strdup("42", "42", 3, "Digit", &is_valid);
    test_strdup("!@#$%^&*()", "!@#$%^&*()", 4, "Other", &is_valid);
    test_strdup("his is a longer test strTing.", "his is a longer test strTing.", 5, "Long.", &is_valid);

    if (is_valid)
    {
        printf("\nft_strdup ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_strdup ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
