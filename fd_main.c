#include "libft/libft.h"
#include <fcntl.h>

//Ok ekse, so like we are running out of time to implement this new logic into the code,
//however, this is the way forward with GNL_, you know, for refining it;
//Just push it and then we'll  get back to later;

int		main(int argc, char **argv)
{
	int		fd;

	if (argc < 2)
	{
		ft_putendl("Could not find a file to read from, harde ntwana;");
		return (0);
	}
	fd = open("foo.txt", O_RDWR | O_CREAT);
	if (fd == -1)
	{
		ft_putendl("Could not open foo.txt ekse, harde ntwana;");
		ft_putstr("the _fd returned is: ");
		ft_putnbr(fd);
		ft_putchar('\n');
	}
	ft_putendl_fd(argv[1], fd);
	close(fd);
	return (0);
}
