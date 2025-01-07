/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:54:21 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/08 02:37:22 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

