#include "ft_ping.h"

static inline void	print_infos(struct addrinfo *server_infos, char *server, char *ip_)
{
	struct sockaddr_in	*ipv4;
	char			ip[INET6_ADDRSTRLEN];
	struct in_addr		*addr;
	char			tmp_host[64];

	
	ipv4 = (struct sockaddr_in *)server_infos->ai_addr;
	addr = &ipv4->sin_addr;
	inet_ntop(server_infos->ai_family, addr, ip, sizeof(ip));
	printf("SPAMMING %s%s%s (%s%s%s)\n", GREEN, server, DEF, GREEN, ip, DEF);
	ft_memcpy(ip_, &ip, sizeof(ip));
	ft_bzero(tmp_host, 64);
	if (getnameinfo(server_infos->ai_addr, sizeof(*server_infos->ai_addr), (char *)&tmp_host, 64, NULL, 0, 0) != 0)
		perror("getnameinfo");
	else
		ft_memcpy(server, tmp_host, 64);
}

bool				establish_connexion(int *sock, char *server, char *ip)
{
	struct addrinfo	*server_infos;

	if (getaddrinfo(server, "http", NULL, &server_infos) != 0
			|| server_infos == NULL)
	{
		dprintf(2, "ft_ping: unknown host %s\n", server);
		return (false); 
	}
	print_infos(server_infos, server, ip);
	if ((*sock = socket(AF_INET, SOCK_RAW, PROTOCOL)) < 0)
	{
		perror("socket");
		freeaddrinfo(server_infos);
		return (false);
	}
	if (connect(*sock, server_infos->ai_addr, server_infos->ai_addrlen) != 0)
	{
		perror("connect");
		freeaddrinfo(server_infos);
		close(*sock);
		return (false);
	}
	freeaddrinfo(server_infos);
	return (true);
}
