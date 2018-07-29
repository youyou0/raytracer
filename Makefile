CC	=	gcc

NAME	= 	raytracer

SRCS	=	$(wildcard *.c)

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	+= 	-Wextra -Wall -Werror -I./include/ -g3

LDFLAGS += 	-L./lib/ -lmy -lbtree

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
		del $(OBJS)

fclean: 	clean
		del $(NAME).exe

re: 		clean fclean all

.PHONY: 	all
