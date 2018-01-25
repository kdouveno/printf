NAME = pf
SRC_PATH = src
SRC_NAME = main.c\
			ft_printf.c\
			pf_putchar.c\
			pf_putint.c\
			pf_charsets.c\
			pf_double.c\
			pf_string.c\
			pf_size_secure.c
OBJ_PATH = obj
CFLAGS = -I includes -I libft/includes
FLAGS = -Wall -Werror -Wextra
RM = rm -f

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) libft/*.c libft/includes/*.h
	@make -C libft
	@gcc $(FLAGS) $(CFLAGS) $(SRC) -Llibft -lft -o $(NAME)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Create printf"

obj/%.o: src/%.c
	@mkdir -p obj
	@gcc $(FLAGS) $(CFLAGS) -c $< -o $@
	@printf '\033[35m[ ✔ ] %s\n\033[0m' "$<"

clean:
	@make -C libft clean
	@RM -f $(OBJ)
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "clean complete"

fclean: clean
	@make -C libft fclean
	@RM -f $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "fclean complete"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re, norme
