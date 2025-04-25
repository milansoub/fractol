CC=cc
CFLAGS=-Wextra -Werror -Wall
SRC=src/ft_printf.c src/process1.c src/process2.c src/ft_print_hex.c src/ft_print_pointer.c src/ft_print_uint.c
HEADERS=inc/ft_printf.h
OBJ=$(SRC:.c=.o)
NAME=libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -crs $@ $(OBJ)

%.o : %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
