#include "philo.h"

static	void	assign_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		philo->first_fork = &philo->table->forks[philo->id - 1];
		philo->second_fork = &philo->table->forks[philo->id % philo->table->philo_nbr];
	}
	else
	{
		philo->first_fork = &philo->table->forks[philo->id % philo->table->philo_nbr];
		philo->second_fork = &philo->table->forks[philo->id - 1];
	}
}

void	init(t_table *table) 
{
	int	i;

	i = -1;
	table->all_threads_ready = false;
	pthread_mutex_init(&table->table_mutex, NULL);
	table->end = false;
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!table->philos)
		error_exit("Error: malloc failed\n");
	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	if (!table->forks)
		error_exit("Error: malloc failed\n");
	while (++i < table->philo_nbr)
	{
		table->forks[i].fork_id = i;
		pthread_mutex_init(&table->forks[i].fork, NULL);
		table->philos[i].id = i + 1;
		table->philos[i].meals = 0;
		table->philos[i].is_full = false;
		table->philos[i].last_meal_time = 0;
		table->philos[i].is_dead = false;
		assign_forks(&table->philos[i]);
		table->philos[i].table = table;
	}
}