/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:59:45 by mg                #+#    #+#             */
/*   Updated: 2024/08/14 14:09:52 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

// Renvoie 1 si entre 32 - 126!
void test_isprint(int test, int attendu, int nbr_test, const char *name, int *is_valid) 
{
    int result = ft_isprint(test);
    if (result != attendu) 
	{
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: %d | obtenu: %d | tester -> [%c]\n", nbr_test, name, attendu, result, test);
        *is_valid = 0;
    }
	else
        printf("Test %d (%s) \033[32m[PASSED]\033[0m \n", nbr_test, name);
}

int main(void)
{
    int is_valid = 1;

    test_isprint('8', 1, 1, "Digit", &is_valid);
    test_isprint('Z', 1, 2, "Upper", &is_valid);
    test_isprint('a', 1, 3, "Lower", &is_valid);        
    test_isprint('%', 1, 4, "Other", &is_valid);
	test_isprint(127, 0, 5, "Delet", &is_valid);
	test_isprint(0, 0, 4, "isNUL", &is_valid);



    if (is_valid)
	{
        printf("\nft_isprint ✅\n");
		printf("\n");
	}

	else
	{
        printf("\nft_isprint ❌\n");
		printf("\n");
	}
    return 0;
}