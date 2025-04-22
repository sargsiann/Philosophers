#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *var, bool value)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}

bool	get_bool(pthread_mutex_t *mutex, bool *var)
{
	bool	value;

	pthread_mutex_lock(mutex);
	value = *var;
	pthread_mutex_unlock(mutex);
	return (value);
}