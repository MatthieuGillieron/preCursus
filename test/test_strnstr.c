/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:31:10 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:38:27 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void test_strnstr(const char *haystack, const char *needle, size_t len, const char *expected, int nbr_test, const char *name, int *is_valid)
{
    char *result = ft_strnstr(haystack, needle, len);

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

    char haystack1[] = "Hello, world!";

    // Tests
	test_strnstr(haystack1, "world", 13, haystack1 + 7, 1, "World", &is_valid); // Trouver 'world' dans 'Hello, world!'
	test_strnstr(haystack1, "world", 5, NULL, 2, "Wrld5", &is_valid); // Trouver 'world' dans les 5 premiers caractères
	test_strnstr(haystack1, "", 13, haystack1, 3, "Empty", &is_valid); // Trouver une chaîne vide dans 'Hello, world!'
	test_strnstr(haystack1, "Hello", 13, haystack1, 4, "Hell.", &is_valid); // Trouver 'Hello' dans 'Hello, world!'
	test_strnstr(haystack1, "world!", 12, NULL, 5, "Insuf", &is_valid); // Trouver 'world!' avec une longueur insuffisante
	test_strnstr(haystack1, "!", 13, haystack1 + 12, 6, "!!!!!", &is_valid); // Trouver '!' dans 'Hello, world!'
	test_strnstr(haystack1, "Hello, world!", 13, haystack1, 7, "Full.", &is_valid); // Trouver la chaîne complète dans elle-même
	test_strnstr(haystack1, "Hello, world!!!", 13, NULL, 8, "Long.", &is_valid); // Trouver une chaîne plus longue que 'haystack'
	test_strnstr("", "Hello", 5, NULL, 9, "Empty", &is_valid); // Trouver 'Hello' dans une chaîne vide


    // Afficher le résultat global des tests
    if (is_valid)
    {
        printf("\nft_strnstr ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_strnstr ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
