/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:15:03 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/28 22:07:59 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		k;
	char	p;

	if (s == NULL)
		return ;
	k = 0;
	while (s[k] != '\0')
	{
		write(fd, &s[k], 1);
		k++;
	}
	p = '\n';
	write(fd, &p, 1);
}
