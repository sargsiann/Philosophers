/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:29:22 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/06 20:56:38 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef pthread_mutex_t mutex_t;

typedef struct s_data t_data;

typedef struct s_fork {
	int		fork_id;
	mutex_t	fork_mutex;
}	t_fork;


typedef struct s_philo {
	int			philo_id;
	long		meals_eaten;
	int			is_full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	philo_thread;	
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	long		num_of_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		num_of_meals;
	long 		start_time;
	int			end;
	t_philo	*philos;
	t_fork	*forks;
}	t_data;

void	error(char *str);
int		check_data(t_data *data, char **argv);
int		init_data(t_data *data);

#endif