/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:57:56 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 22:57:22 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

void test_toupper(int c, int expected, int nbr_test, const char *name, int *is_valid)
{
    int result = ft_toupper(c);

    if (result != expected)
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: '%c' (%d) | obtenu: '%c' (%d)\n", nbr_test, name, expected, expected, result, result);
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

    // Test 1 : Lettre minuscule
    test_toupper('a', 'A', 1, "LowZ.", &is_valid);

    // Test 2 : Lettre minuscule à la fin de l'alphabet
    test_toupper('z', 'Z', 2, "LowZ.", &is_valid);

    // Test 3 : Lettre majuscule (devrait rester la même)
    test_toupper('A', 'A', 3, "UppZ.", &is_valid);

    // Test 4 : Lettre majuscule à la fin de l'alphabet (devrait rester la même)
    test_toupper('Z', 'Z', 4, "UppZ.", &is_valid);

    // Test 5 : Chiffre (ne devrait pas changer)
    test_toupper('1', '1', 5, "Digt1", &is_valid);

    // Test 6 : Caractère non alphabétique (ne devrait pas changer)
    test_toupper('%', '%', 6, "Sym%.", &is_valid);

    // Test 7 : Caractère spécial (caractère nul)
    test_toupper(0, 0, 7, "Null.", &is_valid);

    // Test 8 : Caractère spécial (DEL)
    test_toupper(127, 127, 8, "DEL..", &is_valid);

    if (is_valid)
    {
        printf("\nft_toupper ✅\n");
        printf("_______________________\n");
        printf("\n");
		printf("-----------------------\n");
		printf("****** PARTIE 2 *******\n");
		printf("-----------------------\n");



    }
    else
    {
        printf("\nft_toupper ❌\n");
        printf("_______________________\n");
        printf("\n");
		printf("-----------------------\n");
		printf("****** PARTIE 2 *******");
		printf("-----------------------\n");
    }

    return 0;
}
