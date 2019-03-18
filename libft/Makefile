
NAME = libft.a

FLAGS = -Wall -Wextra -Werror 

SRCS = *.c

OBJS = *.o

INCS = ./

RM = rm -f

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc -Wall -Wextra -Werror -I$(INCS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all