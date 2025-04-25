CC = cc
CFLAGS = -Wextra -Wall -Werror
SRC =	src/main.c\
		src/utils.c\
		src/utils2.c\
		src/mandelbrot.c\
		src/julia.c\
		src/user_input.c\
		src/input.c\
		src/atof.c\
		src/atof2.c\
		src/input2.c\
		src/burning_ship.c

HEADERS = inc/fractol.h
OBJ = $(SRC:.c=.o)
NAME = bin/fractol
LIBFT = libft/libft.a
LIBMLX = MLX42/build/libmlx42.a

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(LIBMLX)
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@ -lm -lglfw

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@echo "Compiling Libft"
	@make -C libft

$(LIBMLX) :
	@echo "Compiling MLX42"
	@cmake MLX42/ -B MLX42/build
	@make -C MLX42/build/ -j4

clean :
	rm -f $(OBJ)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	@echo "Cleaning Libft"
	@make fclean -C libft
	@echo "Cleaning MLX42"
	@make clean -C MLX42/build

re : fclean all

.PHONY : all clean fclean re
