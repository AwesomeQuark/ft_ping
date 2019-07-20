#include "ft_ping.h"

int		main(int ac, char **av)
{
	int		opt;
	char		server[64];

	if (ac < 2)
	{
		dprintf(2, USAGE);
		return (EXIT_SUCCESS);
	}
	wrapper();
	if ((opt = get_opt(ac, av, EXISTING_OPT)) == -1)
		return (EXIT_SUCCESS);
	ft_strncpy((char *)&server, av[ac - 1], 64);
	if (!(ping(opt, (char *)&server)))
		return (EXIT_FAILURE);
	printf("Success\n");
	return (EXIT_SUCCESS);
}
