#include "philo.h"

bool	is_digit(int c) 
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

long	ft_atol(const char *str) 
{
	long		result;

	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+') 
	{
		if (*str == '-')
			error_exit("Error: Cant be passed negative Arguments\n");
		str++;
	}
	if (!is_digit(*str))
		error_exit("Error: Invalid Argument\n");
	while (*str >= '0' && *str <= '9') 
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (result > INT_MAX)
		error_exit("Error: Argument is too large\n");
	return (result);
}

int	ft_strlen(const char *s) 
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	error_exit(const char *s) {
	write(2,s,ft_strlen(s));
	exit(1);
}