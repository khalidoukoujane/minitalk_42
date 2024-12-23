CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
LIBPRINTF = libftprintf/libftprintf.a
CLIENT_SRC = client.c
SERVER_SRC = server.c

all : $(CLIENT) $(SERVER)

$(SERVER) : $(LIBPRINTF) minitalk.h
	$(CC) $(CFLAGS) $(SERVER_SRC) $< -o $@

$(CLIENT) : $(LIBPRINTF) minitalk.h
	$(CC) $(CFLAGS) $(CLIENT_SRC) $< -o $@

$(LIBPRINTF) :
	make -C ./libftprintf

clean :
	make -C ./libftprintf clean

fclean : clean
	rm -f $(CLIENT) $(SERVER)
	make -C ./libftprintf fclean

re : fclean all