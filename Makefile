NAME = philo

CC = cc 

CFLAGS = #-Wall -Wextra -Werror

PHILO_SRCS = $(shell find philo_main -name "*.c")

PHILO_OBJS = $(PHILO_SRCS:.c=.o)

PHILO_DEPS = $(shell find philo_main/includes -name "*.h") Makefile

%.o: %.c $(PHILO_DEPS) -I philo_main/includes
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(PHILO_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PHILO_OBJS)

clean:
	rm -f $(PHILO_OBJS)
	
fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re