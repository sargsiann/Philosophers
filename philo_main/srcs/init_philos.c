/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:58:53 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/16 01:34:52 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_phillos(t_philo *philos)
{
	t_philo *tmp = philos;

	if (!philos)
	{
		printf("No philosophers.\n");
		return;
	}

	printf("Philosopher list:\n");
	do
	{
		printf("Philo ID: %d, Prev ID: %d, Next ID: %d\n",
			tmp->id,
			tmp->prev ? tmp->prev->id : -1,
			tmp->next ? tmp->next->id : -1);
		tmp = tmp->next;
	} while (tmp != philos);
}


t_philo	*new_philo(char **argv, int i, pthread_mutex_t *forks)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	philo->id = i;
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->philo_num = ft_atoi(argv[1]);
	if (argv[5])
		philo->num_of_eat = ft_atoi(argv[5]);
	else
		philo->num_of_eat = -1;
	philo->right_fork = &forks[i];
	philo->left_fork = &forks[(i + 1) % ft_atoi(argv[1])];
	return (philo);
}

void	add_philo(t_philo **philos, t_philo *philo)
{
	t_philo *last;

	if (!(*philos))
	{
		*philos = philo;
		philo->next = philo;
		philo->prev = philo;
		return;
	}
	last = (*philos)->prev;
	last->next = philo;
	philo->prev = last;
	philo->next = *philos; 
	(*philos)->prev = philo;
}

t_philo	*init_philos(pthread_t *threads, char **argv, pthread_mutex_t *forks)
{
	int				i;
	t_philo			*philos;
	t_philo			*tmp;
	pthread_mutex_t	write_lock;

	i = 0;
	philos = NULL;
	pthread_mutex_init(&write_lock, NULL);
	while (i < ft_atoi(argv[1]))
	{
		tmp = new_philo(argv, i, forks);
		tmp->write_lock = &write_lock;
		add_philo(&philos, tmp);
		pthread_create(&threads[i], NULL, philo_action, tmp);
		tmp->thread = &threads[i];
		i++;
	}
	return (philos);
}
