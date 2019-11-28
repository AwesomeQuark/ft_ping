#include "spam.h"

__attribute__((noreturn))
void	statistics(int signo)
{
	(void)signo;
	printf ("\n%d packet sent\n", stats.paquet_counter);
	if (stats.loss != 0)
		printf("\033[31m%d failure\033[0m\n", stats.loss);
	else
		printf("Everything was okay !\n");
	exit(EXIT_SUCCESS);
}

void	sig_handler(void)
{
	for (int i = 0; i < NSIG; i++)
		if (i != SIGBUS && i != SIGSEGV && i != SIGFPE && i != SIGTSTP && i != SIGCONT)
			signal(i, statistics);
}

