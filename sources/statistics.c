#include "ft_ping.h"

struct timeval	get_time(void);

t_statistic *stats = NULL;

void	statistics(int signo)
{
	(void)signo;
	struct timeval	t;
	unsigned long	tot_time;

	t = get_time();
	tot_time = stats->time - (t.tv_sec * 1000 + t.tv_usec);
	printf("\n--- %s ping statistics ---\n", stats->hostname);
	printf ("%d packet transmitted, %d received, %d%% packet loss, time %ld ms\n", stats->paquet_counter, stats->paquet_counter - stats->loss, stats->loss / stats->paquet_counter * 100, tot_time);
	printf("rtt min/avg/max/mdev = x/x/x/x ms\n");
	free(stats);
	exit(EXIT_SUCCESS);
}

void	wrapper(void)
{
	int	i;

	i = 0;
	while (i < NSIG)
	{
		if (i != SIGWINCH)
			signal(i, statistics);
		i++;
	}
}
