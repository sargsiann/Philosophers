#include "philo.h"

int main(int argc, char **argv) 
{
	t_table	table;
	if (argc >= 5 && argc <= 6) 
	{
		parse(&table, argv);
		if (table.philo_nbr == 0)
			error_exit("Error: Number of philosophers must be greater than 0\n");
		init(&table);
		
	}
	else	
		error_exit("Error: Wrong number of arguments\n");
}	