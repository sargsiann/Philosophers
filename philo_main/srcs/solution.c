/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:27:56 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/15 20:35:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	solution(pthread_t *philos, pthread_mutex_t *forks, int num)
{
	while (1)
	{
		if (is_died(philos, num))
		{
			ft_join_and_destroy(philos, forks, num);
			return ;
		}
	}
}
