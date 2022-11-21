NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C libft/
	cp libft/libft.a $(NAME)
	ar -rcs $@ $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

test: re
	cc libft/ft_strlen.c ft_printf.c ft_printf_aux1.c ft_printf_aux2.c ../../42_my_testers/jquintin-ft_printf-tester/ft_printf_test.c && ./a.out

re: fclean all

.PHONY: all clean fclean re
