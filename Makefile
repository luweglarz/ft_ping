CC = gcc

NAME = ft_ping

LIB = ft_ping.a

LIBFT = libft/

FLAGS = -Wall -Wextra -Werror

SRCS =  $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

PWD = $(shell pwd)

.c.o:
	$(CC) $(FLAGS) -I./include -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(LIB) $(OBJS)
	@ranlib $(LIB)
	make -C $(LIBFT) all
	$(CC) $(FLAGS) -I./include ./src/ft_ping.c $(LIB) $(LIBFT)libft.a -o $(NAME)

docker:
	@docker build -t image .
	@docker run  --name container -it --rm -v $(PWD):/ft_ping image /bin/bash

clean:
	rm -rf $(OBJS) $(LIB)
	
fclean:	clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean
	-docker image rm image

re: fclean all