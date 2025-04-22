#ifndef PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h> 
# include <sys/time.h>
# include <limits.h>

typedef struct s_table	t_table;

// FORK IS THE STRUCT FOR MUTEX

typedef struct s_fork
{
	pthread_mutex_t fork;
	int				fork_id;
}	t_fork;

// PHILOSOPHER IS THE STRUCT ID,LFT FORK,RGHT FORK, MEALS, last meal time, isDied, thread id 

typedef struct s_philo
{
	int			id;
	long		meals;
	bool		is_full;
	long		last_meal_time;
	bool		is_dead;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

// TABLE IS STRUCT FOR INFO ABOUT SIMULATION WITH ARRAYS OF PHILOS AND FORKS

struct s_table
{
	int		philo_nbr;
	long	time_to_die;
	long	time_to_sleep;
	long	time_to_eat;
	long	meals_limit;
	long	sim_start;
	bool	end;
	bool	all_threads_ready;
	pthread_mutex_t table_mutex;
	t_fork	*forks;
	t_philo	*philos;
};

void	error_exit(const char *s);
long	ft_atol(const char *str);
void	parse(t_table *table, char **argv);
void	init(t_table *table);
void	dinner(t_table *table);
void	simulation(void	*data);
void	set_bool(pthread_mutex_t *mutex, bool *var, bool value);
bool	get_bool(pthread_mutex_t *mutex, bool *var);
long	get_long(pthread_mutex_t *mutex, long *var);
void	set_long(pthread_mutex_t *mutex, long *var, long value);


# endif