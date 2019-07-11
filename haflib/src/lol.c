#include <libc.h>

int		main()
{
	char	*buff = NULL;
	if (read(15, &buff, 15) < 0)
		perror("main");
}
