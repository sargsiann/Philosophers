/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 02:26:08 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/08 02:28:23 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	wait_all_threads(t_data *data)
{
	while (get_bool(&data->access_mutex, &data->is_all_ready) == 0)
		;
}