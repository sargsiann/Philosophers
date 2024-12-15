/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:11:46 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/16 01:37:58 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philo(t_philo *philo)
{
	t_philo *tmp;

	if (!philo)
		return ;
	tmp = philo;
	while (tmp)
	{
		free(tmp);
		pthread_join(*(tmp->thread), NULL);
		tmp = tmp->next;
	}
}

void	ft_join_and_destroy(t_philo *philos, pthread_mutex_t *forks, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(philos->left_fork);
		pthread_mutex_destroy(philos->right_fork);
		i++;
	}
	free(forks);
	forks = NULL;
	free(philos);
	philos = NULL;
}

int		is_died(t_philo *philo)
{
	t_philo *tmp;

	if (!philo)
		return (0);
	tmp = philo;
	if (get_time() - tmp->last_eat > tmp->time_to_die)
	{
		print_status(tmp, DIE);
		return (1);
	}
	return (0);
}

void	ft_usleep(int time)
{
	__uint64_t start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

__uint64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(philo->write_lock);
	printf("Philosopher %d %s\n", philo->id + 1, status);
	pthread_mutex_unlock(philo->write_lock);
}