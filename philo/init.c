/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:59:18 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/09 21:49:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	init_forks(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->forks[i].fork_id = i;
		if (pthread_mutex_init(&data->forks[i].fork_mutex, NULL))
		{
			error("Error: mutex init failed");
			return 0;
		}
		i++;
	}
	return (1);
}

static void	init_philos(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].philo_id = i;
		data->philos[i].meals_eaten = 0;
		data->philos[i].is_full = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_of_philos];
		data->philos[i].data = data;
		i++;
	}
 }

int	init_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!data->philos)
	{
		error("Malloc Error");
		return (0);
	}
	init_philos(data);
	data->forks = malloc(sizeof(t_fork) * data->num_of_philos);
	if (!data->forks)
	{
		error("Malloc Error");
		return (0);
	}	
	if (!init_forks(data))
		return (0);
	return (1);
}