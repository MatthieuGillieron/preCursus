/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:59:45 by mg                #+#    #+#             */
/*   Updated: 2024/08/14 20:52:15 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

// Renvoie 1 si CHAR !
void test_isalpha(int test, int attendu, int nbr_test, const char *name, int *is_valid) 
{
    int result = ft_isalpha(test);
    if (result != attendu) 
	{
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: %d | obtenu: %d | tester -> ['%c']\n", nbr_test, name, attendu, result, test);
        *is_valid = 0;
    }
	else
        printf("Test %d (%s) \033[32m[PASSED]\033[0m \n", nbr_test, name);
}

int main(void)
{
    int is_valid = 1;

    test_isalpha('a', 1, 1, "Lower", &is_valid);
    test_isalpha('Z', 1, 2, "Upper", &is_valid);
    test_isalpha('1', 0, 3, "Digit", &is_valid);        
    test_isalpha('%', 0, 4, "Other", &is_valid);

    if (is_valid)
	{
        printf("\nft_isalpha ✅\n");
		printf("_______________________\n");
		printf("\n");
	}

	else
	{
        printf("\nft_isalpha ❌\n");
		printf("_______________________\n");
		printf("\n");
	}
    return 0;
}