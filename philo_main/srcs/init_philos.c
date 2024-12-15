/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:58:53 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/15 21:02:54 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


t_philo	*new_philo(char **argv, int i, pthread_mutex_t *forks)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	philo->id = i;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_of_eat = ft_atoi(argv[5]);
	else
		philo->num_of_eat = -1;
	philo->right_fork = &forks[i];
	philo->left_fork = &forks[(i + 1) % ft_atoi(argv[1])];
	return (philo);
}

void	add_philo(t_philo *philos, t_philo *philo)
{
	t_philo *tmp;

	tmp = philos;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = philo;
	philo->prev = tmp;
}

void	init_philos(pthread_t *threads, char **argv, pthread_mutex_t *forks, t_philo *philos)
{
	int		i;
	t_philo *tmp;

	i = 0;
	philos = new_philo(argv, i,  forks);
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(threads + i, NULL, &philo, NULL);
		tmp = new_philo(argv, i,  forks);
		add_philo(philos, tmp);
		i++;
	}
}