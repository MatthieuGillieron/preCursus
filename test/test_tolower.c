/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:00:30 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:32:10 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

void test_tolower(int c, int expected, int nbr_test, const char *name, int *is_valid)
{
    int result = ft_tolower(c);

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

	test_tolower('A', 'a', 1, "UppA.", &is_valid); // Lettre majuscule 'A'
	test_tolower('Z', 'z', 2, "UppZ.", &is_valid); // Lettre majuscule 'Z'
	test_tolower('a', 'a', 3, "LowA.", &is_valid); // Lettre minuscule 'a' (devrait rester la même)
	test_tolower('z', 'z', 4, "LowZ.", &is_valid); // Lettre minuscule 'z' (devrait rester la même)
	test_tolower('1', '1', 5, "Dgt1.", &is_valid); // Chiffre '1' (ne devrait pas changer)
	test_tolower('%', '%', 6, "Sym%.", &is_valid); // Caractère non alphabétique '%'
	test_tolower(0, 0, 7, "Null.", &is_valid); // Caractère spécial nul
	test_tolower(127, 127, 8, "Del..", &is_valid); // Caractère spécial DEL

	if (is_valid)
	{
		printf("\nft_tolower ✅\n");
		printf("_______________________\n");
		printf("\n");
	}
	else
	{
		printf("\nft_tolower ❌\n");
		printf("_______________________\n");
		printf("\n");
	}
	return 0;
} 
