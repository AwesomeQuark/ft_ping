#ifndef FT_PING_H
# define FT_PING_H

# include <sys/socket.h>
# include <sys/types.h>
# include <netdb.h>
# include <unistd.h> 
# include <printf.h>
# include <arpa/inet.h>
# include <stdbool.h>
# include <netinet/in.h> 
# include <netinet/ip_icmp.h>
# include <netinet/ip.h>
# include "haflib.h"

# define USAGE "Usage: ./ft_ping [-abcdefghijklmnopqrstuvwxyz] [server]\n"
# define EXISTING_OPT "abcdefghijklmnopqrstuvwxyz"
# define A_OPT 2
# define B_OPT 4


bool	establish_connexion(int *sock, char *server, char *service);
int		get_opt(int ac, char **av, char *set);
bool	ping(int opt,  char *server);

#endif
