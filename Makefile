NAME = philo

#NAME_BONUS = bonus

CC = cc 

CFLAGS = #-Wall -Wextra -Werror

PHILO_SRCS = $(shell find philo_main -name "*.c")

#BONUS_SRCS = $(shell find philo_bonus -name "*.c")

PHILO_OBJS = $(PHILO_SRCS:.c=.o)

#PHILO_OBJS_BONUS = $(BONUS_SRCS:.c=.o)

PHILO_DEPS = $(shell find philo_main/includes -name "*.h") Makefile

#PHILO_BONUS_DEPS = $(shell find philo_bonus/includes -name "*.h") Makefile

# %.o: %.c $(PHILO_BONUS_DEPS)
# 	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c $(PHILO_DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

# # bonus: $(PHILO_OBJS_BONUS)
# 	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(PHILO_OBJS_BONUS)

$(NAME): $(PHILO_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PHILO_OBJS)

clean:
	rm -f $(PHILO_OBJS)
	
fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re