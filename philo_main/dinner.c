#include "philo.h"

void	simulation(void	*data){
	t_philo	*philo;

	philo = (t_philo *)data;
	
}

void	dinner(t_table *table) {
	int	i;

	i = -1;
	if (table->meals_limit == 0)
		return ;
	if (table->philo_nbr == 1)
		;

	// CREATING THREADS FOR EACH PHILOSOPHER
	while (++i < table->philo_nbr) {
		pthread_create(&table->philos[i].thread_id, NULL, &simulation, &table->philos[i]);
	}
}