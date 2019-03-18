# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 15:05:50 by cdenys-a          #+#    #+#              #
#    Updated: 2019/01/26 17:02:57 by cdenys-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
F = -Wall -Wextra -Werror
F_INCL = -Ilibft
SRCS = print.c read.c solve.c makeawesome.c
OBJS = *.o

all: $(NAME)

$(NAME):
	make -C libft fclean && make -C libft
	gcc $(F) $(F_INCL) -c $(SRCS)
	gcc $(F) $(F_INCL) -L libft -lft -o $(NAME) main.c $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f libft/$(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
