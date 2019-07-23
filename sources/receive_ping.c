#include "ft_ping.h"

unsigned long	receive_answer(int socket)
{
	char		buff[sizeof(struct ip) + sizeof(struct icmp)];
	struct icmp	packet;

	ft_bzero(&buff, sizeof(struct ip) + sizeof(struct icmp));
	if (recv(socket, &buff, sizeof(struct ip) + sizeof(struct icmp), 0) < 0)
		return (0);
	ft_memcpy(&packet, &buff[sizeof(struct ip)], sizeof(struct icmp));
	if (packet.icmp_type != 0 || packet.icmp_code != 0)
		return (0);
	return (get_time());
}
