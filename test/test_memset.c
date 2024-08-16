/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:44:54 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:20:24 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <string.h>

// Fonction pour afficher les valeurs hexadécimales d'un buffer
void print_hex(const void *buffer, size_t length)
{
    const unsigned char *buf = (const unsigned char *)buffer;
    for (size_t i = 0; i < length; i++)
    {
        printf("%02x ", buf[i]);
    }
    printf("\n");
}

void test_memset(void *buffer, int c, size_t len, const char *expected, int nbr_test, const char *name, int *is_valid) 
{
    ft_memset(buffer, c, len);

    if (memcmp(buffer, expected, len) != 0) 
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: ", nbr_test, name);
        print_hex(expected, len);
        printf(" | obtenu: ");
        print_hex(buffer, len);
        *is_valid = 0;
    }
	else
        printf("Test %d (%s) \033[32m[PASSED]\033[0m \n", nbr_test, name);
}

int main(void)
{
    int is_valid = 1;

    // Test 1 : Remplissage de base
    char buffer1[50] = "Hello, world!";
    char expected1[50] = "***** world!";
    test_memset(buffer1, '*', 5, expected1, 1, "Basic", &is_valid);

    // Test 2 : Remplissage avec décalage
    char buffer2[50] = "Hello, world!";
    char expected2[50] = "Hello, *****";
    test_memset(buffer2 + 7, '*', 5, expected2 + 7, 2, "Ofset", &is_valid);

    // Test 3 : Remplissage avec longueur zéro
    char buffer3[50] = "Hello, world!";
    char expected3[50] = "Hello, world!";
    test_memset(buffer3, '*', 0, expected3, 3, "ZeroL", &is_valid);

    // Test 4 : Remplissage complet avec caractère nul
    char buffer4[50] = "Hello, world!";
    char expected4[50] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";
    test_memset(buffer4, '\0', 13, expected4, 4, "FNULL", &is_valid);

    if (is_valid)
	{
        printf("\nft_memset ✅\n");
		printf("_______________________\n");
		printf("\n");
	}
	else
	{
        printf("\nft_memset ❌\n");
		printf("_______________________\n");
		printf("\n");
	}
}