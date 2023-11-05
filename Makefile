CC = gcc

NAME = ft_ping

LIB = ft_ping.a

LIBFT = libft/

FLAGS = -Wall -Wextra -Werror

SRCS =  $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

PWD = $(shell pwd)

INCLUDE = -I./include -I./libft

.c.o:
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(LIB) $(OBJS)
	@ranlib $(LIB)
	make -C $(LIBFT) all
	$(CC) $(FLAGS) $(INCLUDE) ./src/ft_ping.c $(LIB) $(LIBFT)libft.a -o $(NAME)

docker:
	@docker build -t $(NAME) .
	@docker run  --name container -it --rm -v $(PWD):/ft_ping $(NAME) /bin/bash

clean:
	rm -f $(OBJS) $(LIB)
	
fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean
	-docker image rm $(NAME)

re: fclean all