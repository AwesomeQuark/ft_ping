#include "ft_ping.h"

static inline uint16_t ip_checksum(void* vdata, size_t length)
{
	char*		data;
	uint32_t	acc;
	uint16_t	word;
	size_t		i;

	data = (char *)vdata;
	acc = 0xffff;
	i = 0;
	word = 0;
	while (i + 1 < length)
	{
		ft_memcpy(&word, data + i, 2);
		acc += ntohs(word);
		if (acc > 0xffff)
			acc -= 0xffff;
		i += 2;
	}
	if (length & 1)
	{
		word = 0;
		ft_memcpy(&word, data + length - 1, 1);
		acc += ntohs(word);
		if (acc > 0xffff)
			acc -= 0xffff;
	}
	return htons(~acc);
}

unsigned long	send_packet(int socket)
{
	struct icmp	packet;
	struct timeval timeout;

	timeout.tv_sec = 0;
	timeout.tv_usec = 1000;
	setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
	ft_bzero(&packet, sizeof(packet));
	packet.icmp_type = ICMP_TYPE;
	packet.icmp_code = ICMP_CODE;
	packet.icmp_cksum = ip_checksum(&packet, sizeof(packet));
	if (!(send(socket, &packet, sizeof(packet), 0)))
		return (0);
	return (get_time());
} 
