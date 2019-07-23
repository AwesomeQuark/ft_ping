#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

static inline char	exceptions(int e, int r, int *p)
{
	if ((r == 1 || r == 13) && *p == 8)
		write(1, "           ", 11);
	else if ((r == 1 || r == 13) && *p == 15)
	{
		*p = 23;
		return (1);
	}
	else if ((r != 13 && r != 1) && (*p == 8 || *p == 17)) // Passages centraux
		write(1, " ", 1);
	return (0);
		
}
static inline void	call_ping(char *host)
{
	char	command[64];
	char	ret[2];
	FILE	*f;

	bzero(command, 64);
	strcat(command, "./ft_ping -a ");
	strcat(command, host);
	system(command);
}


static inline void	fill_host(int e, int r, int p, char *buff)
{
	char	tmp[16];

	bzero(tmp, 16);
	bzero(buff, 32);
	strcat(buff, "e");
	sprintf(tmp, "%d", e);
	strcat(buff, tmp);
	strcat(buff, "r");
	sprintf(tmp, "%d", r);
	strcat(buff, tmp);
	strcat(buff, "p");
	sprintf(tmp, "%d", p);
	strcat(buff, tmp);
	strcat(buff, ".42.fr");
}

int	main(void)
{
	char	host[32];

	for (int e = 1; e <= 3; e++)
	{
		printf("\n\033[31m##### CLUSTER N%d ######\033[0m\n", e);
		for (int r = 1; r <= 13; r++)
		{
			for (int p = 1; p <= 23; p++)
			{
				if (exceptions(e, r, &p))
					continue ;
				fill_host(e, r, p, host);
				call_ping(host);	
			}
			printf("\n");	
		}
	}
}
