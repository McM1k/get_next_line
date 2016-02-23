/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:52:53 by gboudrie          #+#    #+#             */
/*   Updated: 2016/02/23 15:33:43 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	allocLess(char **line, char **str)
{
	int		size;
	char	*tmp;

	size = ft_strchr(*str, '\n') - *str;
	*line = ft_strsub(*str, 0, size);
	tmp = *str;
	*str = ft_strsub(tmp, size + 1, ft_strlen(tmp) - (size + 1));
	ft_strdel(&tmp);
	return (1);
}

static char	*allocMore(char **str, char *buf)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strjoin(tmp, buf);
	ft_strdel(&tmp);
	return (*str);
}

static int	reader(int rd, char **str, int fd)
{
	char 	*buf;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!*str)
	{
		rd = read(fd, buf, BUFF_SIZE);
		buf[rd] = '\0';
		*str = ft_strsub(buf, 0, BUFF_SIZE);
	}
	while (!ft_strchr(*str, '\n') && rd > 0)
	{
		rd = read(fd, buf, BUFF_SIZE);
		if (rd > 0)
		{
			buf[rd] = '\0';
			*str = allocMore(str, buf);
		}
	}
	ft_strdel(&buf);
	return (rd);
}

int			get_next_line(int const fd, char ** line)
{
	static char		*str = NULL;
	int				rd;

	if ((rd = reader(1, &str, fd)) == -1)
		return (-1);
	if (rd > 0)
	{
		if (ft_strchr(str, '\n'))
			return (allocLess(line, &str));
		else
		{
			*line = ft_strdup(str);	
			return (1);
		}
	}	
	else
		return (0);
}
