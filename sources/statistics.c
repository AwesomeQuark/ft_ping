#include "ft_ping.h"

__attribute__((destructor))
void	statistics(__unused int signo)
{
	stats.init_time = get_time() - stats.init_time;
	printf("\n--- %s ping statistics ---\n", stats.hostname);
	printf ("%d packet transmitted, %d received, %d%% packet loss, time %ld ms\n", stats.paquet_counter, stats.paquet_counter - stats.loss, stats.loss / stats.paquet_counter * 100, stats.init_time);
	printf("rtt min/avg/max/mdev = x/x/x/x ms\n");
}

void	sig_wrapper(void)
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
