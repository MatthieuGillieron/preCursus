/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:24:42 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:07:48 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

// Fonction pour exécuter les tests de `ft_memchr`
void test_memchr(const void *s, int c, size_t n, const void *expected, int nbr_test, const char *name, int *is_valid)
{
    void *result = ft_memchr(s, c, n);

    if (result != expected)
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: %p | obtenu: %p\n", nbr_test, name, expected, result);
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

    // Déclaration des tests
    char str1[] = "Hello, world!";
    test_memchr(str1, 'w', 13, str1 + 7, 1, "FindW", &is_valid);
    test_memchr(str1, 'z', 13, NULL, 2, "FindZ", &is_valid);
    test_memchr(str1, 'H', 5, str1, 3, "FindH", &is_valid);
    test_memchr(str1, ',', 13, str1 + 5, 4, "Find,", &is_valid);
    test_memchr(str1, 'o', 5, str1 + 4, 5, "Findo", &is_valid);
    test_memchr(str1, 'o', 13, str1 + 4, 6, "F1sto", &is_valid);
    test_memchr(str1, '!', 13, str1 + 12, 7, "Find!", &is_valid);
    test_memchr(str1, 'H', 0, NULL, 8, "FindH", &is_valid);

    // Afficher le résultat global des tests
    if (is_valid)
    {
        printf("\nft_memchr ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_memchr ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
