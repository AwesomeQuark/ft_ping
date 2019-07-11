#include "ft_ping.h"

bool				establish_connexion(int *sock, char *server, char *service)
{
	struct addrinfo	*server_infos;

	if (getaddrinfo(server, service, NULL, &server_infos) != 0
		|| server_infos == NULL)
	{
		perror("getaddrinfo: ");
		return (false);
	}
	void *addr;
	char ipstr[INET6_ADDRSTRLEN], ipver;
	printf("Connecting to %s : %s\n", server, server_infos->ai_canonname);
	while (server_infos != NULL)
	{
		struct sockaddr_in *ipv4 = (struct sockaddr_in *)server_infos->ai_addr;
		addr = &(ipv4->sin_addr);
		ipver = '4';
		inet_ntop(server_infos->ai_family, addr, ipstr, sizeof ipstr);
		printf(" IPv%c: %s\n", ipver, ipstr);
		server_infos = (struct addrinfo	*)server_infos->ai_addr;
	}
	if ((*sock = socket(server_infos->ai_family, SOCK_RAW,
		IPPROTO_RAW)) != 0)
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
