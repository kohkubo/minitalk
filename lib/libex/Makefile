# ***********************************

NAME	= libex.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3
obj		= $(src:%.c=%.o)

.PHONY: all clean fclean re debug sani-debug

# ***********************************

src =\
	./strsort.c \
	./free_string_array.c \
	./get_next_line.c \
	./free_set.c \
	./errlst.c \
	./ft_xmalloc.c \
	./ft_fatal.c \
	./ft_strerror.c \
	./ft_strndup.c \
	./contain.c \
	./ft_isspace.c \
	./ft_strcmp.c \
	./ft_xstrdup.c \
	./ft_xcalloc.c \
	./ft_quick_sort.c \
	./ft_error_exit.c \
	./safe_free.c \
	./is_available_pid.c \
	show_unsigned_char_bit.c \

# ***********************************

all: $(NAME)

$(NAME): $(obj)
	$(AR) -rc $(NAME) $(obj)
	ranlib $(NAME)

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# ***********************************

debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 -g"

sani-debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -D DEBUG=1 -g -fsanitize=address"
