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

# define USAGE "Usage: ./ft_ping [-v] [server]\n\
\t-s: No coldown between those pings hey\n\
\t-a: Only one request, and return only 1 on success, and 0 on failure\n"
# define EXISTING_OPT "as"
# define A_OPT 2
# define B_OPT 4
# define C_OPT 8
# define D_OPT 16
# define E_OPT 32
# define F_OPT 64
# define G_OPT 128
# define H_OPT 256
# define I_OPT 512
# define J_OPT 1024
# define K_OPT 2048
# define L_OPT 4096
# define M_OPT 8192
# define N_OPT 16384
# define O_OPT 32768
# define P_OPT 65536
# define Q_OPT 131072
# define R_OPT 262144
# define S_OPT 524288 

typedef struct	s_statistic
{
	char			hostname[64];
	int				paquet_counter;
	int				loss;
	unsigned long	init_time;
	int				*times;
}		t_statistic;

extern t_statistic stats;

bool				establish_connexion(int opt, int *sock, char *service, char *ip);
int					get_opt(int ac, char **av, char *set);
void				ping_loop(int opt, int socket, char *ip);
unsigned long		get_time(void);
void				statistics(int signo);
unsigned long		send_packet(int socket);
unsigned long		receive_answer(int socket);
void				sig_handler(void);

#endif
