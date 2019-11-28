#include "ft_ping.h"

void	statistics(int signo)
{
	(void)signo;
	printf ("\n%d packet sent\n", stats.paquet_counter);
	printf("%d failure\n", stats.loss);
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
		i++;
	}
}

