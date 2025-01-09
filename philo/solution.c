/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:04:05 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/09 21:29:15 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*dinner(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->data);
	philo->last_meal_time = get_time();
	while (get_bool(&philo->data->access_mutex,
		&philo->data->end) == 0) 
	{
		if (philo->data->num_of_meals != 0 
			&& philo->meals_eaten >= philo->data->num_of_meals)
		{ 
			set_bool(&philo->data->access_mutex, &philo->data->end, 1);
			break ;	
		}
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_philo(philo);
	}
} 

int	start_sim(t_data *data)
{
	int	i;

	i = -1;
	if (data->num_of_meals == 0)
		return (1);
	else if (data->num_of_philos == 1)
		;
	else
	{
		while (++i < data->num_of_philos)
			pthread_create(&data->philos[i].philo_thread, NULL,
				dinner, data->philos + i);
		data->start_time = get_time();
		set_bool(&data->access_mutex, &data->is_all_ready, 1);
		i = -1;
		while (++i < data->num_of_philos)
			pthread_join(data->philos[i].philo_thread, NULL);
	}
}