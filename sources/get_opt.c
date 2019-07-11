#include "ft_ping.h"

static inline bool	find_in_set(char a, char *set)
{
	while (*set)
	{
		if (a == *set)
			return (true);
		set++;
	}
	return (false);
}

static inline char	to_min(char a)
{
	return (a > 'A' ? a : a - 'A');
}

static inline int	pow_of_two(int pow)
{
	int		ret;

	ret = 2;
	while (--pow)
		ret *= 2;
	return (ret);
}

int					get_opt(int ac, char **av, char *set)
{
	int		opt;
	int		i;
	int		j;

	opt = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][0] != '-')
			break ;
		while (av[i][++j])
		{
			if (find_in_set(av[i][j], set) == false)
			{
				dprintf(2, USAGE);
				return (-1);
			}
			opt = opt | pow_of_two(to_min(av[i][j]) - ('a' - 1));
		}
		i++;
	}
	return (opt);
}
