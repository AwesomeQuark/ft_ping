#include "ft_ping.h"

int		check_sum_icmp(struct icmp p)
{
	unsigned short	buff[512];
	size_t		i;
	unsigned int	sum;
	unsigned short	result;

	sum = 0;
	i = 0;
	ft_memcpy(buff, &p, sizeof(p));
	while (buff[i])
		sum += buff[i++]; 
	sum = (sum >> 16) + (sum & 0xFFFF); 
	sum += (sum >> 16); 
	result = ~sum; 
	return (sum);
}

clock_t	receive_answer(int socket)
{
	struct icmp	packet;
	clock_t		time_;

	if (!(read(socket, &packet, sizeof(packet))))
		return (0);
	time_ = clock();
	printf("Answer received\n");
	printf("\tType : %d\n\tCode : %d\n\tCheckSum : %d\n", packet.icmp_type, packet.icmp_code, packet.icmp_cksum);
	return (time_);
}

clock_t	send_packet(int socket)
{
	struct icmp	packet;
	clock_t		time_;
	int	ttl_val = 64;

	setsockopt(socket, SOL_SOCKET, IP_TTL, &ttl_val, sizeof(ttl_val));
	ft_bzero(&packet, sizeof(packet));
	packet.icmp_type = 8;
	packet.icmp_code = 0;
	packet.icmp_cksum = check_sum_icmp(packet);
	if (!(write(socket, &packet, sizeof(packet))))
		return (0);
	time_ = clock();
	printf("Ping sent\n");
	printf("\tType : %d\n\tCode : %d\n\tCheckSum : %d\n", packet.icmp_type, packet.icmp_code, packet.icmp_cksum);
	return (time_);
}

bool	ping(int opt, char *server)
{
	int	socket;
	clock_t	start;
	clock_t	end;

	(void)opt;
	if (establish_connexion(&socket, server, "http") == false)
	{
		dprintf(2, "Failed to establish connection\n");
		return (false);
	}
	if ((start = send_packet(socket)) == 0)
	{
		dprintf(2, "failed to send packet\n");
		return (false);
	};
	if ((end = receive_answer(socket)) == 0)
	{
		dprintf(2, "failed to receive answer\n");
		return (false);
	}
	printf("Time : %ld ms\n", end - start);
	return (true);
}
