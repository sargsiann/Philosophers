/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:00:01 by dasargsy          #+#    #+#             */
/*   Updated: 2024/12/15 15:07:25 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		 check_args(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	if (argc != 5 || argc != 6)
		return (0);
	while (i < argc)
	{
		j = 0;
		if (ft_strcmp(argv[i], "0") == 0)
			return (0);
		while (argv[i][j])
		{
			if (!is_digit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}