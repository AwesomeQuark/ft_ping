#include "ft_ping.h"

static inline void	print_infos(struct addrinfo *server_infos, char *server)
{
	struct sockaddr_in *ipv4;
	struct sockaddr_in6 *ipv6;
	void *addr;
	char ip[INET6_ADDRSTRLEN];

	printf("Connecting to %s : %s\n", server, server_infos->ai_addr->sa_data);
	ipv4 = (struct sockaddr_in *)server_infos->ai_addr;
	addr = &(ipv4->sin_addr);
	inet_ntop(server_infos->ai_family, addr, ip, sizeof(ip));
	printf("\tIPv4: %s\n", ip);
	server_infos = server_infos->ai_next;
	ipv6 = (struct sockaddr_in6 *)server_infos->ai_addr;
	addr = &(ipv6->sin6_addr);
	inet_ntop(server_infos->ai_family, addr, ip, sizeof(ip));
	printf("\tIPv6: %s\n", ip);
	server_infos = server_infos->ai_next;
}

bool				establish_connexion(int *sock, char *server, char *service)
{
	struct addrinfo	*server_infos;
	struct protoent *protocol;

	if (getaddrinfo(server, service, NULL, &server_infos) != 0
		|| server_infos == NULL)
	{
		dprintf(2, "Server not found\n");
		return (false);
	}
	print_infos(server_infos, server);
	protocol = getprotobyname("icmp");
	if ((*sock = socket(server_infos->ai_family, SOCK_RAW, protocol->p_proto)) != 0)
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
