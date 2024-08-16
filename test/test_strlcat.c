#include "../libft/libft.h"

void test_strlcat(char *dest, const char *src, size_t n, size_t expected_length, const char *expected_dest, int nbr_test, const char *name, int *is_valid)
{
    char initial_dest[100];
    strncpy(initial_dest, dest, sizeof(initial_dest));

    size_t result_length = ft_strlcat(dest, src, n);
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

    // Test 1 : Concaténation dans la taille du buffer
    strcpy(buffer, "Hello");
    test_strlcat(buffer, ", world!", 50, strlen("Hello, world!"), "Hello, world!", 1, "Concat", &is_valid);



    // Test 3 : Taille du buffer plus petite que la longueur de la destination
    strcpy(buffer, "Hello");
    test_strlcat(buffer, ", world!", 5, strlen("Hello") + strlen(", world!"), "Hello", 2, "Small", &is_valid);

    // Test 4 : Taille du buffer plus petite que la longueur du résultat
    strcpy(buffer, "Hello");
    test_strlcat(buffer, ", world!", 10, strlen("Hello") + strlen(", world!"), "Hello, wo", 3, "BufSm", &is_valid);

    // Test 5 : Concaténation dans un buffer vide
    strcpy(buffer, "");
    test_strlcat(buffer, "Hello", 50, strlen("Hello"), "Hello", 4, "Empty", &is_valid);

    // Test 6 : Concaténation d'une chaîne vide
    strcpy(buffer, "Hello");
    test_strlcat(buffer, "", 50, strlen("Hello"), "Hello", 5, "Empty", &is_valid);

    // Test 7 : Concaténation avec taille de buffer exacte
    strcpy(buffer, "Hello");
    test_strlcat(buffer, " world!", 13, strlen("Hello") + strlen(" world!"), "Hello world!", 6, "Exact", &is_valid);

    // Afficher le résultat global des tests
    if (is_valid)
    {
        printf("\nft_strlcat ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_strlcat ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
