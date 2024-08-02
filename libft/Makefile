# Nom de la bibliothèque
NAME = libft.a

# Commandes
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
MKDIR = mkdir -p

# Répertoire pour les fichiers objets
OBJDIR = obj

# Répertoire pour les fichiers d'en-tête
INCLUDES_DIR = -I./includes

# Fichiers sources et objets
FILES =	ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_strlen \
		ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_strlcpy \
		ft_strlcat \
		ft_toupper \
		ft_tolower \
		ft_strchr \
		ft_strrchr \
		ft_strncmp \
		ft_memchr \
		ft_memcmp \
		ft_strnstr \
		ft_atoi \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd

FILES_BONUS =	ft_lstnew \
				ft_lstadd_front \
				ft_lstsize \
				ft_lstlast \
				ft_lstadd_back \
				ft_lstdelone \
				ft_lstclear \
				ft_lstiter \
				ft_lstmap \

# Ajout de l'extension .c pour les fichiers sources
SRCS = $(addsuffix .c, $(FILES))
SRCS_BONUS = $(addsuffix .c, $(FILES_BONUS))

# Création des chemins pour les fichiers objets
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES)))
OBJS_BONUS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES_BONUS)))

# Cible par défaut : création de la bibliothèque
all: $(NAME)

# Règle pour créer la bibliothèque
$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "Compilation réussie."
	@echo "La bibliothèque $(NAME) a été créée."

# Compilation des fichiers objets
$(OBJDIR)/%.o: %.c $(HEAD)
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES_DIR) -c $< -o $@

# Compilation des fichiers bonus
bonus: $(OBJS_BONUS)
	@$(AR) $(NAME) $^
	@echo "Bonus ajoutés à la bibliothèque."

# Nettoyage des fichiers objets
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(RM) -r $(OBJDIR)
	@echo "Les fichiers objets ont été supprimés."

# Nettoyage complet
fclean: clean
	@$(RM) $(NAME)
	@echo "La bibliothèque $(NAME) a été supprimée."

# Rebuild complet
re: fclean all

# Déclaration des cibles phony
.PHONY: all clean fclean re bonus
