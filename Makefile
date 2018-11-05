NAME = calculette

LIBFT_DIR = Libft/

SRCS = main.c check.c solver.c check_is_valid.c
OBJ = $(subst .c,.o,$(SRCS))

INC_DIR = .

WFLAGS = -Wall -Werror -Wextra

GCCRESET=\033[0m
GCCMAG=\033[1;35m

all: $(NAME)

$(NAME):
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@make --no-print-directory -C $(LIBFT_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@gcc $(WFLAGS) -c $(SRCS) -I $(INC_DIR)
	@echo "Compilation des fichiers sources $(GCCMAG)<calculette>$(GCCRESET)..."
	@gcc $(WFLAGS) $(OBJ) -I $(INC_DIR) -L $(LIBFT_DIR) -lft -o $(NAME)
	@echo "Creation du binaire $(GCCMAG)<calculette>$(GCCRESET)..."

clean:
	@rm -Rf $(OBJ)
	@echo "Suppression des fichiers objet $(GCCMAG)<calculette>$(GCCRESET)..."

fclean: clean
	@rm -Rf $(NAME)
	@echo "Suppression de l'executable $(GCCMAG)<calculette>$(GCCRESET)..."
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all