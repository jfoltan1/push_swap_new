NAME := push_swap
CC := cc
CFLAGS := -Wall -Wextra -Werror
LIBFT := ../libft
FT_PRINTF := ../ft_printf
LIBS := -L$(LIBFT) -lft -L$(FT_PRINTF) -lftprintf
SRCS := main.c
OBJS := $(SRCS:.c=.o)

all: libft ft_printf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

libft:
	make -C $(LIBFT)

ft_printf:
	make -C $(FT_PRINTF)

bonus: libft
	make -C $(LIBFT) bonus

.c.o:
	$(CC) $(CFLAGS) -I$(LIBFT) -I$(FT_PRINTF) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean
	make -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean
	make -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re libft ft_printf bonus
