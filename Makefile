CC = cc
CFLAGS = -Wall -Wextra -Werror
FILE_NAME = show ft_putnbr ft_putstr ft_putchar putmemory ft_puthxnbr ft_printf verification ft_putpnbr

SRC_FILE = $(FILE_NAME:%=%.c)
OBJ_FILE = $(FILE_NAME:%=%.o)
HEA_FILE = ft_printf.h

NAME = libftprintf.a
	
all : $(NAME)
	

$(NAME) : $(OBJ_FILE)
	ar rcs $(NAME) $(OBJ_FILE)
	

%.o : %.c 
	$(CC) $(CFLAGS) -g -c $< -o $@
	

clean :
	rm -f $(OBJ_FILE)


fclean : clean
	rm -f $(NAME)


re : fclean all

