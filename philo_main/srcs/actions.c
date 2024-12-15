/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:42:57 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/16 01:46:23 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void take_forks(t_philo *philo)
{
    pthread_mutex_t *first_fork, *second_fork;

    if (philo->id < (philo->id + 1) % philo->philo_num) // Consistent ordering
    {
        first_fork = philo->right_fork;
        second_fork = philo->left_fork;
    }
    else
    {
        first_fork = philo->left_fork;
        second_fork = philo->right_fork;
    }

    pthread_mutex_lock(first_fork);
    print_status(philo, FORK1);
    pthread_mutex_lock(second_fork);
    print_status(philo, FORK2);
}

void	put_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	print_status(philo, SLEEP);
}

void *philo_action(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (!philo)
    {
        printf("Invalid philosopher pointer\n");
        return NULL;
    }
    if (philo->id % 2 == 0)
        ft_usleep(philo->time_to_eat / 2);
    while (1)
    {
        take_forks(philo);
        print_status(philo, EAT);
        ft_usleep(philo->time_to_eat);
        pthread_mutex_lock(philo->write_lock);
        philo->last_eat = get_time();
        pthread_mutex_unlock(philo->write_lock);
        put_forks(philo);
        ft_usleep(philo->time_to_sleep);
        print_status(philo, THINK);
    }
    return NULL;
}

