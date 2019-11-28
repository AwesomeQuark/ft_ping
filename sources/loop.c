#include "spam.h"

__attribute__((noreturn))
void	loop(int socket)
{
	// Pretty much self-explantory
	while (1)
	{
		if (send_packet(socket) == false)
		{
			dprintf(2, "failed to send packet\n");
			stats.loss++;
		}
		stats.paquet_counter++;
	}
}

