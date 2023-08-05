# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 13:56:46 by jfoltan           #+#    #+#              #
#    Updated: 2023/08/04 13:56:46 by jfoltan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
CC := cc
CFLAGS :=  -g -Wall -Wextra -Werror
LIBFT := ./libft/
LIBFTFLAGS:= -I$(LIBFT) -Llibft
LIBS := $(LIBFT)libft.a
SRCS    := src/main.c src/push_swap.c src/sortfun.c src/stackfun.c src/utils.c src/we_love_norminette.c
OBJS := $(SRCS:.c=.o)


all:  libft ${NAME}


$(NAME): $(OBJS) $(LIBS)
	$(CC) $^ $(LIBFTFLAGS) -o $(NAME)

libft:
	make -C $(LIBFT)

bonus: libft
	make -C $(LIBFT) bonus

.c.o:
	$(CC) $(CFLAGS) -I. -Ilibft -c -o $@ $<

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft bonus
