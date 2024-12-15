/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:02:00 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/15 20:59:13 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	init_forks(pthread_mutex_t *forks, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init(pthread_mutex_t *forks, pthread_t *threads, char **argv)
{
	int		num;
	t_philo *philos;

	num = ft_atoi(argv[1]);
	forks = malloc(sizeof(pthread_mutex_t) * num);
	init_forks(forks, num);
	threads = malloc(sizeof(pthread_t) * num);
	init_philos(threads, argv, forks, philos);
}