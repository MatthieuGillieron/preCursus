/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:08:33 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:38:15 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/libft.h"

void test_strrchr(const char *str, int c, const char *expected, int nbr_test, const char *name, int *is_valid)
{
    char *result = ft_strrchr(str, c);

    if (result != expected)
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: '%s' | obtenu: '%s'\n", nbr_test, name, expected ? expected : "NULL", result ? result : "NULL");
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

char str1[] = "Hello, world!";

test_strrchr(str1, 'o', str1 + 8, 1, "LastO", &is_valid); // Trouver le dernier 'o' dans la chaîne
test_strrchr(str1, 'z', NULL, 2, "pas2Z", &is_valid); // Chercher 'z' dans str1 (non présent)
test_strrchr(str1, 'H', str1, 3, "FindH", &is_valid); // Trouver 'H' dans str1
test_strrchr(str1, ',', str1 + 5, 4, "Find,", &is_valid); // Trouver ',' dans str1
test_strrchr(str1, '!', str1 + 12, 5, "Find!", &is_valid); // Trouver '!' dans str1
test_strrchr(str1, '\0', str1 + 13, 6, "Null1", &is_valid); // Trouver le caractère nul '\0' dans str1
test_strrchr("", '\0', "", 7, "Null2", &is_valid); // Trouver le caractère nul '\0' dans une chaîne vide

    if (is_valid)
    {
        printf("\nft_strrchr ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_strrchr ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
