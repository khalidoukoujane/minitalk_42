SRCS = ft_itoa.c ft_print_args.c ft_print_hex.c ft_printf.c  ft_printf_utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all