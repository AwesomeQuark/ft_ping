#include "ft_ping.h"

void	statistics(int signo)
{
	(void)signo;
	stats.init_time = get_time() - stats.init_time;
	printf("\n--- %s ping statistics ---\n", stats.hostname);
	printf ("%d packet transmitted, %d received, %d%% packet loss, time %ld ms\n", stats.paquet_counter, stats.paquet_counter - stats.loss, stats.loss / stats.paquet_counter * 100, stats.init_time);
	printf("rtt min/avg/max/mdev = x/x/x/x ms\n");
	exit(EXIT_SUCCESS);
}

void	sig_handler(void)
{
	int		i;

	i = 0;
	while (i < NSIG)
	{
		if (i != SIGBUS && i != SIGSEGV && i != SIGFPE && i != SIGTSTP && i != SIGCONT)
			signal(i, statistics);
	}
}

