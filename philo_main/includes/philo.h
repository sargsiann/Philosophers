/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:28:51 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/15 20:58:17 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "libft.h"

typedef struct s_philo
{
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_of_eat;
	__uint64_t		last_eat;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *write_lock;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;



int		check_args(int argc, char **argv);
void	init_forks(pthread_mutex_t *forks, int num);
void	init_philos(pthread_t *threads, char **argv, pthread_mutex_t *forks, t_philo *philos);
void	init(pthread_mutex_t *forks, pthread_t *philos, char **argv);
void	*philo(void *arg);
void	solution(pthread_t *philos, pthread_mutex_t *forks, int num);
void	ft_join_and_destroy(pthread_t *philos, pthread_mutex_t *forks, int num);
int		is_died(pthread_t *philos, int num);

#endif
