/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:52:53 by gboudrie          #+#    #+#             */
/*   Updated: 2016/02/08 22:32:49 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	allocLess(char **line, char *str)
{
	int		size;
	char	*tmp;
	
	size = ft_strchr(str, '\n') - str;
	*line = ft_strsub(str, 0, size);
	tmp = str;
	str = ft_strsub(tmp, size + 1, ft_strlen(tmp) - (size + 1));
	ft_strdel(&tmp);
	return (1);
}

static char	*allocMore(char *str, char *buf)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(tmp, buf);
	ft_strdel(&tmp);
	return (str);
}

int			get_next_line(int const fd, char ** line)
{
	static char		*str = NULL;
	char			buf[BUFF_SIZE];
	int				rd;

	if (!str)
	{
		rd = read(fd, buf, BUFF_SIZE);
		if (rd)
			str = ft_strsub(buf, 0, rd);
	}
	while (read(fd, buf, BUFF_SIZE) > 0 && !(ft_strchr(str, '\n')))
		str = allocMore(str, buf);
	if (ft_strchr(str, '\n'))
		return (allocLess(line, str));
	if (!(read(fd, buf, BUFF_SIZE)))
	{
		if (str)
		{
			*line = ft_strdup(str);
			ft_strdel(&str);
		}
		return (0);
	}
	return (-1);
}
