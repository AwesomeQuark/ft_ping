#include "ft_ping.h"

int		check_sum_icmp(struct icmp p)
{
	char	buff[512];
	size_t	i;
	int		sum;

	sum = 0;
	i = 0;
	ft_memcpy(buff, &p, sizeof(p));
	while (buff[i])
	{
		sum += buff[i];
		i++;
	}
}

int		receive_answer(int socket)
{
	struct icmp packet;

	read(socket, &packet, sizeof(packet));
	write(1, &packet, sizeof(packet));
	return (1);
}

int		send_packet(int socket)
{
	struct icmp packet;

	packet.icmp_type = 8;
	packet.icmp_code = 0;
	packet.icmp_cksum = check_sum_icmp(packet);
	write(socket, &packet, sizeof(packet));
	return (1);
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
	receive_answer(socket);
	return (true);
}