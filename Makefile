# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 20:45:22 by arforouz          #+#    #+#              #
#    Updated: 2023/04/17 20:45:24 by arforouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDE = push_swap.h

SRCS = pushswap.c \
	input_check.c \
	cost.c \
	order.c \
	position.c \
	push.c \
	rev_rotate.c \
	rotate.c \
	stack.c \
	sub_sort.c \
	swap.c \
	utils.c \
	sort.c \
	split.c \


CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
REMOVE = rm -f

%o: %c
	@echo "$<"
	@$(CC) $(CFLAGS) -c $< -o $@

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS) $(INCLUDE)
	@$(CC) $(SRCS) -o $(NAME)

all: $(NAME)

clean: 
	@$(REMOVE) $(OBJS)

fclean:
	@$(REMOVE) $(OBJS)
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
