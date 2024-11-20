NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf_utils.c ft_printf.c\

OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)

all : $(NAME)

clean :
		@rm -rf $(OBJ)

fclean :
		@rm -f $(NAME) $(OBJ)

re : fclean all
