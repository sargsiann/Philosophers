NAME = philo_main

CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find philo -name "*.c")

OBJS = $(SRCS:.c=.o)

DEPS = Makefile philo/header.header

%.o: %.c $(DEPS)
	cc $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re