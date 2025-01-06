SERVER = server
CLIENT = client
CFLAGS = -Wall -Werror -Wextra
CC = cc
PRINTF_SRC = ft_printf/ft_itoa.c ft_printf/ft_print_args.c ft_printf/ft_print_hex.c \
			ft_printf/ft_printf.c ft_printf/ft_printf_utils.c
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)
C_SRC = ./mandatory/client.c
S_SRC = ./mandatory/server.c
C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

all : $(SERVER) $(CLIENT)

$(CLIENT): $(C_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SERVER): $(S_OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

mandatory/%.o : mandatory/%.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

ft_printf/%.o : ft_printf/%.c ft_printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(C_OBJ) $(S_OBJ) $(PRINTF_OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all