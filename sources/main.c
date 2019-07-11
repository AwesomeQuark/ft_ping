#include "ft_ping.h"

int		main(int ac, char **av)
{
	int		opt;

	if (ac < 2)
	{
		dprintf(2, USAGE);
		return (EXIT_SUCCESS);
	}
	if ((opt = get_opt(ac, av, EXISTING_OPT)) == -1)
		return (EXIT_SUCCESS);
	if (!(ping(opt, av[ac - 1])))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
