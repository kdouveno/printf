NAME = libftprintf.a
SRC_PATH = src
SRC_NAME =	ft_printf.c\
			pf_putchar.c\
			pf_putint.c\
			pf_putchard.c\
			pf_putlong.c\
			pf_putllong.c\
			pf_putshort.c\
			pf_charsets.c\
			pf_double.c\
			pf_putstr.c\
			pf_putuni.c\
			pf_putcuni.c\
			pf_putuint.c\
			pf_putulong.c\
			pf_putullong.c\
			pf_putushort.c\
			pf_putuchard.c\
			pf_putoint.c\
			pf_putxint.c\
			pf_putxshort.c\
			pf_putxchard.c\
			pf_putxlong.c\
			pf_putxllong.c\
			pf_putxmaj.c\
			pf_putc.c\
			pf_size_secure.c\
			pf_size_secure_two.c
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
	@libtool -static -o $(NAME) $(OBJ) libft/libft.a
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Create libftprintf.a"

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
