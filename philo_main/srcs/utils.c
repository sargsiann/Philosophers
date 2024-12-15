/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:11:46 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/15 20:58:23 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_join_and_destroy(pthread_t *philos, pthread_mutex_t *forks, int num)
{
	int i;

	i = 0;
	if (!philos || !forks)
		return ;
	while (i < num)
	{
		pthread_join(philos[i], NULL);
		free(&philos[i]);
		i++;
	}
	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&forks[i]);
		free(&forks[i]);
		i++;
	}
	free(forks);
	forks = NULL;
	free(philos);
	philos = NULL;
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(philo->write_lock);
	printf("%ld %d %s\n", get_time() - philo->last_eat, philo->id, status);
	pthread_mutex_unlock(philo->write_lock);
}