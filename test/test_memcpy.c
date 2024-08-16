#include "../libft/libft.h"
#include <string.h>

void test_memcpy(void *dest, const void *src, size_t n, const void *expected, int nbr_test, const char *name, int *is_valid)
{
    ft_memcpy(dest, src, n);

    if (memcmp(dest, expected, n) != 0)
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m  attendu: '%s' | obtenu: '%s'\n", nbr_test, name, (char *)expected, (char *)dest);
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

    // Test 1 : Copie de base
    char dest1[50] = "Hello, world!";
    char src1[50] = "Goodbye!";
    test_memcpy(dest1, src1, 8, "Goodbye!", 1, "Basic", &is_valid);

    // Test 2 : Copie avec chevauchement en avant
    char dest2[50] = "Hello, world!";
    char src2[50] = "Hello, world!";
    test_memcpy(dest2 + 2, src2, 6, "Hello, world!", 2, "forwa", &is_valid);

    // Test 3 : Copie avec chevauchement en arrière
    char dest3[50] = "Hello, world!";
    test_memcpy(dest3, dest3 + 2, 6, "llo, world!", 3, "backw", &is_valid);

    // Test 4 : Copie de longueur zéro
    char dest4[50] = "Hello, world!";
    char src4[50] = "";
    test_memcpy(dest4, src4, 0, "Hello, world!", 4, "ZeroL", &is_valid);

    if (is_valid)
    {
        printf("\nft_memcpy ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_memcpy ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
