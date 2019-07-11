#include "ft_ping.h"

int		send_packet(int socket)
{
	
}

bool	ping(int opt, char *server)
{
	int				socket;

	(void)opt;
	if (establish_connexion(&socket, server, "http") == false)
	{
		dprintf(2, "Failed to establish connection\n");
		return (false);
	}
	send_packet(socket);
	return (true);
}