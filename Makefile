NAME = philo

NAME_BONUS = philo_bonus

CC = cc 

CFLAGS = -Wall -Wextra -Werror

PHILO_SRCS = $(shell find philo/srcs -name "*.c")

BONUS_SRCS = $(shell find philo_bonus/srcs -name "*.c")

PHILO_OBJS = $(PHILO_SRCS:.c=.o)

PHILO_OBJS_BONUS = $(BONUS_SRCS:.c=.o)

PHILO_DEPS = $(shell find philo/includes -name "*.h") Makefile

PHILO_BONUS_DEPS = $(shell find philo_bonus/includes -name "*.h") Makefile

%.o: %.c $(PHILO_BONUS_DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c $(PHILO_DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

bonus: $(PHILO_OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(PHILO_OBJS_BONUS)

$(NAME): $(PHILO_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PHILO_OBJS)

clean:
	rm -f $(PHILO_OBJS)
	rm -f $(PHILO_OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re