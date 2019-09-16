/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:57:22 by mnukeri           #+#    #+#             */
/*   Updated: 2019/07/23 17:01:02 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_next_l(char **fd_holder, char **line, int fd, int red)
{
	char	*temp;
	int		len;

	len = 0;
	while (fd_holder[fd][len] != '\n' && fd_holder[fd][len] != '\0')
		len++;
	if (fd_holder[fd][len] == '\n')
	{
		*line = ft_strsub(fd_holder[fd], 0, len);
		temp = ft_strdup(fd_holder[fd] + len + 1);
		free(fd_holder[fd]);
		fd_holder[fd] = temp;
		if (fd_holder[fd][0] == '\0')
			ft_strdel(&fd_holder[fd]);
	}
	else if (fd_holder[fd][len] == '\0')
	{
		if (red == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(fd_holder[fd]);
		ft_strdel(&fd_holder[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*fd_holder[1024];
	char				buf[BUFF_SIZE + 1];
	char				*temp;
	int			red;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[red] = '\0';
		if (fd_holder[fd] == NULL)
			fd_holder[fd] = ft_strnew(1);
		temp = ft_strjoin(fd_holder[fd], buf);
		free(fd_holder[fd]);
		fd_holder[fd] = temp;
	}
	if (red < 0)
		return (-1);
	else if (red == 0 && (fd_holder[fd] == NULL || *fd_holder[fd] == '\0'))
		return (0);
	return (ft_next_l(fd_holder, line, fd, red));
}


//DO NOT SUBMIT MAIN. 22dd;
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
			ft_putstr(line);
			ft_putchar(' ');
			free(line);
		}
		//close(fd);
		p++;
	}
	close(fd);
	return (0);
}
