#include "ft_ping.h"

bool				establish_connexion(int *sock, char *server, char *service)
{
	struct addrinfo	*server_infos;
	struct addrinfo	hints;

	if (getaddrinfo(server, service, NULL, &server_infos) == -1
		|| server_infos == NULL)
	{
		perror("getaddrinfo: ");
		return (false);
	}
	if ((*sock = socket(server_infos->ai_family, SOCK_RAW,
		IPPROTO_RAW)) == -1)
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
