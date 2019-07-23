#include "ft_ping.h"

t_statistic	stats;

static inline void	init_stats(char *server)
{
	ft_bzero(&stats, sizeof(t_statistic));
	stats.paquet_counter = 1;
	ft_strncpy((char *)stats.hostname, server, 64);
	stats.init_time = get_time();
}

__attribute__((noreturn))
int		main(int ac, char **av)
{
	int			opt;
	int			socket;
	char		ip[INET6_ADDRSTRLEN];

	if (ac < 2)
	{
		dprintf(2, USAGE);
		exit(EXIT_SUCCESS);
	}
	sig_wrapper();
	if ((opt = get_opt(ac, av, EXISTING_OPT)) == -1)
		exit(EXIT_SUCCESS);
	init_stats(av[ac - 1]);
	if (establish_connexion(opt, &socket, stats.hostname, (char *)&ip) == false)
	{
		if (opt & A_OPT)
			printf("0");
		exit(EXIT_FAILURE);
	}
	ping_loop(opt, socket, ip);
}
