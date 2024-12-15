/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:27:56 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/16 01:33:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	solution(t_philo *philos, pthread_mutex_t *forks, int num)
{
	t_philo *tmp;

	tmp = philos;
	if (!philos)
		return ;
	while (1)
	{
		if (is_died(tmp))
		{
			print_status(tmp, DIE);
			ft_join_and_destroy(philos, forks, num);
			return ;
		}
		if (tmp->num_of_eat == 0)
		{
			ft_join_and_destroy(philos, forks, num);
			return ;
		}
	}
}
