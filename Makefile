#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/09 21:35:06 by ytailor           #+#    #+#              #
#    Updated: 2014/03/09 22:02:03 by ytailor          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = puissance4

FLAGS = -Wall -Wextra -Werror -ansi -pedantic

SRCS = main.c ft_check.c ft_init.c ft_print.c ft_read.c ft_ia.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	gcc $(FLAGS) $(SRCS) -o $(NAME) libft/libft.a
%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
