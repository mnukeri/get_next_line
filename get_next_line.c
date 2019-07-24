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

static int		new_line(char **st, char **line, int fd, int red)
{
	char	*temp;
	int		len;

	len = 0;
	while (st[fd][len] != '\n' && st[fd][len] != '\0')
		len++;
	if (st[fd][len] == '\n')
	{
		*line = ft_strsub(st[fd], 0, len);
		temp = ft_strdup(st[fd] + len + 1);
		free(st[fd]);
		st[fd] = temp;
		if (st[fd][0] == '\0')
			ft_strdel(&st[fd]);
	}
	else if (st[fd][len] == '\0')
	{
		if (red == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(st[fd]);
		ft_strdel(&st[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*st[FD_SIZE];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			red;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	while ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[red] = '\0';
		if (st[fd] == NULL)
			st[fd] = ft_strnew(1);
		temp = ft_strjoin(st[fd], buf);
		free(st[fd]);
		st[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (red < 0)
		return (-1);
	else if (red == 0 && (st[fd] == NULL || *st[fd] == '\0'))
		return (0);
	return (new_line(st, line, fd, red));
}

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
		close(fd);
		p++;
	}
	return (0);
}
