CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBS=ft_printf/libftprintf.a
NAME=libft.a
SRC=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BONUS=ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ=$(SRC:.c=.o)
BONUS_OBJ=$(BONUS:.c=.o)
HEADERS=libft.h

all : $(NAME)

$(NAME) : $(OBJ) $(BONUS_OBJ)
	make -C ft_printf
	cp ft_printf/libftprintf.a $(NAME)
	ar -crs $@ $^

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ft_printf
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	make fclean -C ft_printf
	rm -rf $(NAME)

re : fclean all

bonus : $(OBJ) $(BONUS_OBJ)
	ar -crs $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY : all clean fclean re bonus
