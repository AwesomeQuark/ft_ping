#include "ft_ping.h"

unsigned long	get_time(void)
{
	struct timeval	tv;
	struct timezone	tz;

	ft_bzero(&tv, sizeof(tv));
	ft_bzero(&tz, sizeof(tz));
	gettimeofday(&tv, &tz);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

__attribute__((noreturn))
void	ping_loop(int opt, int socket, char *ip)
{
	unsigned long	start;
	unsigned long	end;
	long		interval;

	while (1)
	{
		interval = 0;
		if ((start = send_packet(socket)) == 0)
		{
			if (!(opt & A_OPT))
				dprintf(2, "failed to send packet\n");
			stats.loss++;
		}
		if ((end = receive_answer(socket)) == 0)
		{
			if (!(opt & A_OPT))
				dprintf(2, "failed to receive answer\n");
			stats.loss++;
		}
		else
		{
			if (opt & A_OPT)
			{
				printf("1");
				exit(EXIT_SUCCESS);
			}
			interval = end - start;
			printf("64 bytes from %s%s%s (%s%s%s): icmp_seq=%s%d%s ttl=64 time=%s%.2f%s ms\n", YELLOW, stats.hostname, DEF, YELLOW, ip, DEF, GREEN, stats.paquet_counter, DEF, RED, (float)interval / 100, DEF);			stats.paquet_counter++;
		}
		if (opt & A_OPT)
		{
			printf("0");
			exit(EXIT_FAILURE);
		}
		if (!(opt &S_OPT))
			usleep(930000 - interval);
	}
}

