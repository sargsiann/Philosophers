/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:05:04 by dasargsy          #+#    #+#             */
/*   Updated: 2025/01/06 20:48:47 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (-2);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	check_ispint(char *str)
{
	int	i;
	int len;
	long num;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			len++;
		i++;
	}
	if (len > 11)
		return (-2);
	num = ft_atoi(str);
	if (num < 0 || num > INT_MAX)
		return (-2);
	return (num);
}

int	check_data(t_data *data, char **av)
{
	data->num_of_philos = check_ispint(av[1]);
	data->time_to_die = check_ispint(av[2]);
	data->time_to_eat = check_ispint(av[3]);
	data->time_to_sleep = check_ispint(av[4]);
	data->num_of_meals = check_ispint(av[5]);
	if (data->num_of_philos == -2 || data->time_to_die == -2
		|| data->time_to_eat == -2 || data->time_to_sleep == -2
		|| data->num_of_meals == -2)
	{
		error("Invalid arguments");
		return (0);
	}	
	return (1);
}