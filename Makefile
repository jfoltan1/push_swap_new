NAME := push_swap
CC := cc
CFLAGS :=  -g -Wall -Wextra -Werror
LIBFT := ./libft
LIBS := -L$(LIBFT) -lft
SRCS    := main.c push_swap.c sortfun.c stackfun.c utils.c
OBJS := $(SRCS:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

libft:
	make -C $(LIBFT)

bonus: libft
	make -C $(LIBFT) bonus

.c.o:
	$(CC) $(CFLAGS) -I$(LIBFT) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft bonus
