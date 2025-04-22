#include "philo.h"

void	parse(t_table *table, char **argv) 
{
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (argv[5])
	{
		table->meals_limit = ft_atol(argv[5]);
	}
	else
		table->meals_limit = -1;
	if (table->time_to_die > 600000 || table->time_to_eat > 60000 || table->time_to_sleep > 60000)
		error_exit("Error: Time to die, eat or sleep is too long\n");
}