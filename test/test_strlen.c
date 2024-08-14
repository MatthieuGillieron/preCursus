/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:59:45 by mg                #+#    #+#             */
/*   Updated: 2024/08/14 14:21:41 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void test_strlen(const char *str, int attendu, int nbr_test, const char *name, int *is_valid) 
{
    int result = ft_strlen(str);
    if (result != attendu) 
	{
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m attendu: %d | obtenu: %d | tester -> \"%s\"\n", nbr_test, name, attendu, result, str);
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

    // Différents cas de test pour `ft_strlen`
    test_strlen("", 0, 1, "Empty", &is_valid);
    test_strlen("Hello", 5, 2, "Hello", &is_valid);
    test_strlen("42", 2, 3, "Digit", &is_valid);
    test_strlen(" ", 1, 4, "Space", &is_valid);
    test_strlen("This is a longer string.", 24, 5, "isSTR", &is_valid);
    test_strlen("A\tB\tC", 5, 6, "STabs", &is_valid);
    test_strlen("\nNewline", 8, 7, "Nline", &is_valid);

    // Afficher le résultat global des tests
    if (is_valid)
	{
        printf("\nft_strlen ✅\n");
		printf("\n");
	} 
	else 
	{
        printf("\nft_strlen ❌\n");
		printf("\n");
	}

    return 0;
}