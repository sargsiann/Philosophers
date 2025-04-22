#include "philo.h"

int main(int argc, char **argv) 
{
	t_table	table;
	if (argc >= 5 && argc <= 6) 
	{
		parse(&table, argv);
	}
	else if (argv[0][0] == '0'){
		error_exit("Error: Wrong number of philos\n");
	}
	else	
		error_exit("Error: Wrong number of arguments\n");
}	