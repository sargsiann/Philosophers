/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:42:18 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/16 01:35:49 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int main(int argc, char **argv) 
{
    pthread_t		*threads;
	t_philo			*philos;
	pthread_mutex_t *forks;

	philos = NULL;
	forks = NULL;
	if (!check_args(argc, argv))
	{
		printf("Invalid arguments\n");
		return (1);
	}
	philos = init(forks, threads, argv);
	// solution(philos, forks, ft_atoi(argv[1]));
    ft_join_and_destroy(philos, forks, ft_atoi(argv[1]));
	return 0;
}

