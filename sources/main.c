#include "ft_ping.h"

t_statistic	stats;

static inline void	init_stats(char *server)
{
	ft_bzero(&stats, sizeof(t_statistic));
	stats.paquet_counter = 1;
	ft_strncpy((char *)stats.hostname, server, 64);
}

int		main(int ac, char **av)
{
	int			socket;
	char		ip[INET6_ADDRSTRLEN];

	if (ac < 2)
	{
		dprintf(2, USAGE);
		return (EXIT_SUCCESS);
	}
	sig_handler();
	init_stats(av[ac - 1]);
	if (establish_connexion(&socket, stats.hostname, (char *)&ip) == false)
	{
		return (EXIT_FAILURE);
	}
	ping_loop(socket, ip);
}
