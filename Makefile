NAME	= libftprintf.a
SRCS	= main.c \
	utils/ft_putchar.c \
	utils/ft_putstr.c \
	utils/ft_putnbr.c \
	utils/ft_putnbr_ui.c \
	utils/ft_putptr.c \
	utils/ft_puthex.c \
	utils/ft_dec_to_hex.c
OBJS	= $(SRCS:.c=.o)
HEADERS	= libftprintf.h
CC	= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)
	@ranlib $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
