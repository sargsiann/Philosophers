/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:50:11 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/06 20:55:47 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clean(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i].fork_mutex);
		free(&data->forks[i]);
		free(&data->philos[i]);
		i++;
	}
	free(data->forks);
}

void	join_threads(t_data *data)
{
	
}

int main(int ac, char **av)
{
	t_data	data;
	
	if (ac == 5 || ac == 6)
	{
		if (!check_data(&data, av))
			return (1);
		if (!init_data(&data))
		{
			
		}
	}
	else
	{
		error("Invalid number of arguments");
		return (1);
	}	
}