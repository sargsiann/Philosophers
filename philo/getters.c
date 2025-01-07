/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 02:19:36 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/08 02:24:00 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_bool(mutex_t *m, short *data, short val)
{
	pthread_mutex_lock(m);
	*data = val;
	pthread_mutex_unlock(m);
}

short	get_bool(mutex_t *m, short *data)
{
	short	val;

	pthread_mutex_lock(m);
	val = *data;
	pthread_mutex_unlock(m);
	return (val);
}

void	set_long(mutex_t *m, long *data, long val)
{
	pthread_mutex_lock(m);
	*data = val;
	pthread_mutex_unlock(m);
}

long	get_long(mutex_t *m, long *data)
{
	long	val;

	pthread_mutex_lock(m);
	val = *data;
	pthread_mutex_unlock(m);
	return (val);
}
