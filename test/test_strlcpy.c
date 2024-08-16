/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:12:23 by mg                #+#    #+#             */
/*   Updated: 2024/08/16 11:16:18 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void test_strlcpy(char *dest, const char *src, size_t d_size, size_t expected_length, const char *expected_dest, int nbr_test, const char *name, int *is_valid)
{
    // Réinitialiser dest avec une chaîne connue
    strcpy(dest, "Initial");

    // Appel de la fonction à tester
    size_t result_length = ft_strlcpy(dest, src, d_size);

    // Vérifier la longueur de retour et le contenu de dest
    if (result_length != expected_length || strcmp(dest, expected_dest) != 0)
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: longueur: %zu | contenu: '%s' | obtenu: longueur: %zu | contenu: '%s'\n", nbr_test, name, expected_length, expected_dest, result_length, dest);
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
    char buffer[50];

    // Test 1 : Copie dans la taille du buffer
    test_strlcpy(buffer, "Hello, world!", 50, strlen("Hello, world!"), "Hello, world!", 1, "Copy.", &is_valid);

    // Test 2 : Taille du buffer nulle
    test_strlcpy(buffer, "Hello, world!", 0, strlen("Hello, world!"), "Initial", 2, "Zero.", &is_valid);

    // Test 3 : Taille du buffer plus petite que la source
    test_strlcpy(buffer, "Hello, world!", 5, strlen("Hello, world!"), "Hell", 3, "Small", &is_valid);

    // Test 4 : Copie dans un buffer vide
    test_strlcpy(buffer, "Hello", 50, strlen("Hello"), "Hello", 4, "Empty", &is_valid);

    // Test 5 : Copie d'une chaîne vide
    test_strlcpy(buffer, "", 50, 0, "", 5, "Empty", &is_valid);

    // Test 6 : Copie avec taille de buffer exacte
    test_strlcpy(buffer, "Hello", 6, strlen("Hello"), "Hello", 6, "Exact", &is_valid);

    // Afficher le résultat global des tests
    if (is_valid)
    {
        printf("\nft_strlcpy ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_strlcpy ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
