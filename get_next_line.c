/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:52:53 by gboudrie          #+#    #+#             */
/*   Updated: 2016/02/08 17:46:05 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char ** line)
{
	static char		*str = NULL;
	char			buf[BUFF_SIZE];
	int				rd;
	char			*tmp;

	if (!str)
	{
		rd = read(fd, buf, BUFF_SIZE);
		if (rd)
			str = ft_strsub(buf, 0, rd);
	}
	while (read(fd, buf, BUFF_SIZE) > 0 && !(ft_strchr(str, '\n')))
	{
		tmp = str;
		str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	if (ft_strchr(str, '\n'))
	{
		*line = ft_strsub(str, 0, ft_strchr(str, '\n') - str);
		tmp = str;
		str = ft_strsub(tmp, ft_strchr(str, '\n') - str + 1, ft_strlen(tmp) - (ft_strchr(str, '\n') - str + 1));
		ft_strdel(&tmp);
		return (1);
	}
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
