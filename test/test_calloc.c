/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:38:11 by mg                #+#    #+#             */
/*   Updated: 2024/08/15 19:35:16 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void test_calloc(size_t count, size_t size, int nbr_test, const char *name, int *is_valid)
{
    void *result = ft_calloc(count, size);
    void *expected = calloc(count, size);

    if (result == NULL || expected == NULL || memcmp(result, expected, count * size) != 0)
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m\n", nbr_test, name);
        *is_valid = 0;
    }
    else
    {
        printf("Test %d (%s) \033[32m[PASSED]\033[0m\n", nbr_test, name);
    }

    free(result);
    free(expected);
}

int main(void)
{
    int is_valid = 1;

    test_calloc(5, sizeof(int), 1, "5 int", &is_valid);
    test_calloc(10, sizeof(char), 2, "10cha", &is_valid);
    test_calloc(0, sizeof(int), 3, "Zero.", &is_valid);
    test_calloc(1, sizeof(double), 4, "Oned.", &is_valid);
    test_calloc(100, sizeof(float), 5, "100 F", &is_valid);

    if (is_valid)
    {
        printf("\nft_calloc ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_calloc ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
