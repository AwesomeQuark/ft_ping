#include "ft_ping.h"

static inline void	print_infos(struct addrinfo *server_infos, char *server)
{
	void *addr;
	char ipstr[INET6_ADDRSTRLEN];
	printf("Connecting to %s : %s\n", server, server_infos->ai_addr->sa_data);
	struct sockaddr_in *ipv4 = (struct sockaddr_in *)server_infos->ai_addr;
	addr = &(ipv4->sin_addr);
	inet_ntop(server_infos->ai_family, addr, ipstr, sizeof(ipstr));
	printf(" IPv4: %s\n", ipstr);
	server_infos = server_infos->ai_next;
	struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)server_infos->ai_addr;
	addr = &(ipv6->sin6_addr);
	inet_ntop(server_infos->ai_family, addr, ipstr, sizeof(ipstr));
	printf(" IPv6: %s\n", ipstr);
	server_infos = server_infos->ai_next;
}

bool				establish_connexion(int *sock, char *server, char *service)
{
	struct addrinfo	*server_infos;

	if (getaddrinfo(server, service, NULL, &server_infos) != 0
		|| server_infos == NULL)
	{
		perror("getaddrinfo: ");
		return (false);
	}
	print_infos(server_infos, server);
	if ((*sock = socket(server_infos->ai_family, SOCK_RAW,
		0)) != 0)
	{
		perror("socket: ");
		freeaddrinfo(server_infos);
		return (false);
	}
	if (connect(*sock, server_infos->ai_addr, server_infos->ai_addrlen) < 0)
	{
		perror("connect: ");
		freeaddrinfo(server_infos);
		close(*sock);
		return (false);
	}
	freeaddrinfo(server_infos);
	return (true);
}
