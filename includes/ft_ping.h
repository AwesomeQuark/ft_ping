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
# include <time.h>
# include <sys/time.h>
# include <signal.h>
# include "haflib.h"

# define USAGE "Usage: ./ft_ping [-v] [server]\n\t-v: No coldown between those pings hey\n"
# define EXISTING_OPT "abcdefghijklmnopqrstuvwxyz"
# define A_OPT 2
# define B_OPT 4
# define F_OPT 32
# define S_OPT 524288 

typedef struct	s_statistic
{
	char	hostname[64];
	int	paquet_counter;
	int	loss;
	long	time;
	int	*times;
}		t_statistic;

extern t_statistic *stats;

bool	establish_connexion(int opt, int *sock, char *server, char *service, char *ip);
int	get_opt(int ac, char **av, char *set);
bool	ping(int opt,  char *server);
void	wrapper(void);

#endif
