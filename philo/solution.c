/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:04:05 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/06 21:38:53 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*dinner(void *data); 

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
	}
}