#include "ft_ping.h"

__attribute__((noreturn))
void	ping_loop(int socket, char *ip)
{
	while (1)
	{
		if (send_packet(socket) == 0)
		{
			dprintf(2, "failed to send packet\n");
			stats.loss++;
		}
		stats.paquet_counter++;
	}
}

