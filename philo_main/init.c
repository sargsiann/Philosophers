#include "philo.h"

void	init(t_table *table) 
{
	int	i;

	i = -1;
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
		table->philos[i].right_fork = &table->forks[i];
		table->philos[i].left_fork = &table->forks[(i + 1) % table->philo_nbr];
		table->philos[i].table = table;
	}
}