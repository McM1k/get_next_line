/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:52:53 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/19 20:33:10 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int const fd, char ** line)
{
	static char		*buf;
	int				rd;
	int				i;

	if (buf[0] == '\0')
	{
		rd = read(fd, buf, BUF_SIZE);
		buf = (char *)malloc(rd);
	}
	i = 0;
	while (buf[i] != \n)
	{
		if (buf[i] == '\0')
		{
			rd = read(fd, buf, BUF_SIZE);
			buf = (char *)malloc(rd);
		}
		i++;
	}
}
