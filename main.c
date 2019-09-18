#include "get_next_line.h"

int				main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int			p;

	p = 1;
	while (p <= argc)
	{
		fd = open(argv[p], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			ft_putendl(line);
			free(line);
		}
		p++;
	}
	close(fd);
	return (0);
}
