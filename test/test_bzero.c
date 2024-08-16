/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:58:47 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:18:09 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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

void test_bzero(void *buffer, size_t len, const char *expected, int nbr_test, const char *name, int *is_valid) 
{
    bzero(buffer, len);

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

    // Test 1 : Remplacement de base
    char buffer1[50] = "Hello, world!";
    char expected1[50] = "\0\0\0\0\0\0\0\0\0\0\0\0\0 world!";
    test_bzero(buffer1, 13, expected1, 1, "Basic", &is_valid);

    // Test 2 : Remplacement avec décalage
    char buffer2[50] = "Hello, world!";
    char expected2[50] = "Hello, \0\0\0\0\0\0\0\0\0\0!";
    test_bzero(buffer2 + 7, 5, expected2 + 7, 2, "Ofset", &is_valid);

    // Test 3 : Remplacement avec longueur zéro
    char buffer3[50] = "Hello, world!";
    char expected3[50] = "Hello, world!";
    test_bzero(buffer3, 0, expected3, 3, "ZeroL", &is_valid);

    // Test 4 : Remplacement complet
    char buffer4[50] = "Hello, world!";
    char expected4[50] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    test_bzero(buffer4, 50, expected4, 4, "FullB", &is_valid);

    if (is_valid)
    {
        printf("\nft_bzero ✅\n");
        printf("_______________________\n");
    }
    else
    {
        printf("\nft_bzero ❌\n");
        printf("_______________________\n");
    }

    return 0;
}