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

# include "conf.h"

# define USAGE "Usage: ./spam target\n"

typedef struct	s_statistic
{
	char			hostname[64];
	int				paquet_counter;
	int				loss;
}				t_statistic;

extern t_statistic stats;

bool				establish_connexion(int *sock, char *service, char *ip);
void				ping_loop(int socket, char *ip);
void				statistics(int signo);
unsigned long		send_packet(int socket);
void				sig_handler(void);

#endif
