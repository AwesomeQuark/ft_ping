#include "ft_ping.h"

uint16_t ip_checksum(void* vdata, size_t length)
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

struct timeval	get_time(void)
{
	struct timeval	tv;
	struct timezone	tz;

	ft_bzero(&tv, sizeof(tv));
	ft_bzero(&tz, sizeof(tz));
	gettimeofday(&tv, &tz);
	return (tv);
}

struct timeval	receive_answer(int socket)
{
	char		buff[sizeof(struct ip) + sizeof(struct icmp)];
	struct icmp	packet;
	struct timeval	t;

	ft_bzero(&buff, sizeof(struct ip) + sizeof(struct icmp));
	ft_bzero(&t, sizeof(t));
	if (!(read(socket, &buff, sizeof(struct ip) + sizeof(struct icmp))))
		return (t);
	t = get_time();
	ft_memcpy(&packet, &buff[sizeof(struct ip)], sizeof(struct icmp));
	if (packet.icmp_type != 0 || packet.icmp_code != 0)
	{
		printf("Fail !\n");
	}
	return (t);
}

struct timeval	send_packet(int socket)
{
	struct icmp	packet;
	struct timeval	t;
	int	ttl_val = 64;

	setsockopt(socket, SOL_SOCKET, IP_TTL, &ttl_val, sizeof(ttl_val));
	ft_bzero(&packet, sizeof(packet));
	ft_bzero(&t, sizeof(t));
	packet.icmp_type = 8;
	packet.icmp_code = 0;
	packet.icmp_cksum = ip_checksum(&packet, sizeof(packet));
	t = get_time();
	if (!(send(socket, &packet, sizeof(packet), 0)))
		return (t);
	return (t);
}

void	ping_loop(int opt, int socket, char *server, char *ip)
{
	struct timeval	start;
	struct timeval	end;
	long		interval;

	while (1)
	{
		stats->paquet_counter++;
		if ((start = send_packet(socket)).tv_usec == 0)
		{
			dprintf(2, "failed to send packet\n");
			stats->loss++;
		}
		else if ((end = receive_answer(socket)).tv_usec == 0)
		{
			dprintf(2, "failed to receive answer\n");
			stats->loss++;
		}
		else
		{
			interval = end.tv_usec > start.tv_usec ? end.tv_usec - start.tv_usec : start.tv_usec - end.tv_usec;
			printf("64 bytes from %s%s%s (%s%s%s): icmp_seq=%s%d%s ttl=64 time=%s%.2f%s ms\n", YELLOW, server, DEF, YELLOW, ip, DEF, GREEN, stats->paquet_counter, DEF, RED, (float)((float)interval / 1000), DEF);
			if (!(opt & S_OPT))
				usleep(930000 - interval);
			stats->time += interval;
		}
	}
}

bool	init_stats(char *server)
{
	if (!(stats = malloc(sizeof(t_statistic))))
		return (false);
	ft_bzero(stats, sizeof(t_statistic));
	ft_strncpy(stats->hostname, server, 64);
	return (true);
}

bool	ping(int opt, char *server)
{
	int	socket;
	char	ip[INET6_ADDRSTRLEN];

	(void)opt;
	if (establish_connexion(&socket, server, "http", (char *)&ip) == false)
		return (false);
	if (init_stats(server) == false)
		return (false);
	if (opt & S_OPT)
		fork();
	ping_loop(opt, socket, server, ip);
	free(stats);
	return (true);
}
