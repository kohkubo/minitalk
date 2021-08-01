# ***********************************

NAME		= server_client
NAME_SERVER = server
NAME_CLIENT = client
includes 	= -I./includes
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O3 $(includes)
obj			= $(src:%.c=%.o)
obj_server	= $(src_server:%.c=%.o)
obj_client	= $(src_client:%.c=%.o)

.PHONY: all clean fclean re bonus

# ***********************************

src =\
	./srcs/util.c \

src_server =\
	./srcs/server.c \

src_client =\
	./srcs/client.c \

# ***********************************

all: $(NAME)

bonus: $(NAME)

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(obj_server) $(obj)
	$(MAKE) -C ./lib/libft
	$(MAKE) -C ./lib/libex
	$(CC) $(CFLAGS) $(obj) $(obj_server) -o $(NAME_SERVER) ./lib/libft/libft.a ./lib/libex/libex.a

$(NAME_CLIENT): $(obj_client) $(obj)
	$(MAKE) -C ./lib/libft
	$(MAKE) -C ./lib/libex
	$(CC) $(CFLAGS) $(obj) $(obj_client) -o $(NAME_CLIENT) ./lib/libft/libft.a ./lib/libex/libex.a

clean:
	$(RM) $(obj) $(obj_server) $(obj_client)
	@$(MAKE) clean -C ./lib/libft
	@$(MAKE) clean -C ./lib/libex

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@$(MAKE) fclean -C ./lib/libft
	@$(MAKE) fclean -C ./lib/libex

re: fclean all

# ***********************************
