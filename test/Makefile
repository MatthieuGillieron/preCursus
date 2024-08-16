# Répertoires
LIBFT_DIR = ../libft
LIBFT_INC = $(LIBFT_DIR)
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Liste des fichiers sources de test
TEST_SRCS = $(wildcard test_*.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_EXECS = $(TEST_SRCS:.c=.out)

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -lft

# Règle par défaut
all: $(TEST_EXECS)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

# Compilation des exécutables de test
%.out: %.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Nettoyage des fichiers objets et des exécutables
clean:
	rm -f $(TEST_OBJS)

# Nettoyage complet
fclean: clean
	rm -f $(TEST_EXECS)

# Recompilation complète
re: fclean all

# Exécution de tous les tests et suppression des fichiers .out
magillie: $(TEST_EXECS)
	@for exec in $(TEST_EXECS); do \
		echo "Running $$exec"; \
		./$$exec; \
		rm -f $$exec; \
	done

.PHONY: all clean fclean re magillie
