#include "../libft/libft.h"

void test_strncmp(const char *s1, const char *s2, size_t n, int expected, int nbr_test, const char *name, int *is_valid)
{
    int result = ft_strncmp(s1, s2, n);

    if ((result < 0 && expected >= 0) || (result > 0 && expected <= 0) || (result == 0 && expected != 0))
    {
        printf("Test %d (%s) \033[31m[FAILURE]\033[0m attendu: %d | obtenu: %d\n", nbr_test, name, expected, result);
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

	test_strncmp("abcde", "abcde", 5, 0, 1, "StrId", &is_valid); // Compare identical strings
	test_strncmp("abcde", "abcdf", 5, -1, 2, "StrDf", &is_valid); // Compare different strings
	test_strncmp("abcde", "abcdF", 5, 1, 3, "StrCs", &is_valid); // Compare case-sensitive strings
	test_strncmp("abc", "abcdef", 3, 0, 4, "StrCp", &is_valid); // Compare strings with common prefix
	test_strncmp("abc", "abcdef", 5, -1, 5, "StrLn", &is_valid); // Compare strings with common prefix and longer n
	test_strncmp("abcdef", "abc", 3, 0, 6, "StrLs", &is_valid); // Compare longer string with shorter string (n = 3)
	test_strncmp("abcdef", "abc", 6, 1, 7, "StrL6", &is_valid); // Compare longer string with shorter string (n = 6)
	test_strncmp("12345", "12345", 5, 0, 8, "NumId", &is_valid); // Compare numeric strings
	test_strncmp("12345", "12346", 5, -1, 9, "NumDf", &is_valid); // Compare numeric strings with last digit different
	test_strncmp("", "", 1, 0, 10, "Rien", &is_valid); // Compare empty strings

    if (is_valid)
    {
        printf("\nft_strncmp ✅\n");
        printf("_______________________\n");
        printf("\n");
    }
    else
    {
        printf("\nft_strncmp ❌\n");
        printf("_______________________\n");
        printf("\n");
    }

    return 0;
}
