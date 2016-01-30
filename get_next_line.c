/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:52:53 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/30 19:24:00 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_addalloc(char **line, char *buf, int len)
{
	char	*new_line;

	new_line = ft_strnew(ft_strlen(*line) + len - 1);
	strcpy(new_line, *line);
	strncat(new_line, buf, len);
	free(*line);
	line = &new_line;
	return (line);
}

int			get_next_line(int const fd, char ** line)
{
	static char		*str;		
	char			*buf[BUFF_SIZE];
	int				rd;
	int				i;
	int				len;

	while ((rd = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (!(ft_strchr(buf, '\n')))
			len = rd;
		else
			len = ft_strchr(buf, '\n') - buf;
		if (str)
			str = ft_addalloc(&str, buf, );
		else
			str = ft_strsub(buf, 0, rd);
		if ()
	}
}
