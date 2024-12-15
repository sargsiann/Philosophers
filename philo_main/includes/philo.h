/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:28:51 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/16 00:46:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include "libft.h"


# define FORK1		"has taken a fork1"
# define FORK2		"has taken a fork2"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DIE		"died"

typedef struct s_philo
{
	int				id;
	int				philo_num;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_of_eat;
	__uint64_t		last_eat;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *write_lock;
	pthread_t		*thread;
	struct s_philo	*next;
	struct s_philo	*prev;	
}	t_philo;



int		check_args(int argc, char **argv);
t_philo	*init(pthread_mutex_t *forks, pthread_t *threads, char **argv);
void	init_forks(pthread_mutex_t *forks, int num);
t_philo	*init_philos(pthread_t *threads, char **argv, pthread_mutex_t *forks);
void	*philo_action(void *arg);
void	solution(t_philo *philos, pthread_mutex_t *forks, int num);
void	ft_join_and_destroy(t_philo *philos, pthread_mutex_t *forks, int num);
int		is_died(t_philo *philos);
void	ft_usleep(int time);
void	print_status(t_philo *philo, char *status);
__uint64_t	get_time(void);

#endif
