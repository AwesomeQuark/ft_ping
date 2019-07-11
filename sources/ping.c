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
	return (sum);
}

bool	receive_answer(int socket)
{
	struct icmp packet;

	if (!(read(socket, &packet, sizeof(packet))))
		return (false);
	printf ("Answer received\n");
	if (!(write(1, &packet, sizeof(packet))))
		return (false);
	return (true);
}

bool	send_packet(int socket)
{
	struct icmp packet;

	packet.icmp_type = 8;
	packet.icmp_code = 0;
	packet.icmp_cksum = check_sum_icmp(packet);
	if (!(write(socket, &packet, sizeof(packet))))
		return (false);
	printf("Ping sent\n");
	return (true);
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
	if (!(send_packet(socket)))
	{
		dprintf("failed to send packet\n");
		return (false);
	};
	if (!(receive_answer(socket)))
	{
		dprintf("failed to receive answer\n");
		return (false);
	}
	return (true);
}