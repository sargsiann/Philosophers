/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:54:21 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/09 21:53:38 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_usleep(size_t milliseconds, t_data *data)
{
    size_t start;

    start = get_current_time();
    while ((get_current_time() - start) < milliseconds)
    {
        if (get_bool(&data->access_mutex, data->end))
            return (1);        
    }
    return (0); 
}

void	write_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (philo->data->end == 0)
		printf("Philo %d %s\n", philo->philo_id + 1, str);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	error(char *str)
{
	printf("%s\n", str);
}

