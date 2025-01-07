/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:04:05 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/08 02:37:46 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*dinner(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->data);
} 

int	start_sim(t_data *data)
{
	int	i;

	i = 0;
	if (data->num_of_meals == 0)
		return (1);
	else if (data->num_of_philos == 1)
		;
	else
	{
		while (i < data->num_of_philos)
		{
			pthread_create(&data->philos[i].philo_thread, NULL,
				dinner, data->philos + i);
			i++;
		}
		data->start_time = get_time();
		set_bool(&data->access_mutex, &data->is_all_ready, 1);
	}
}