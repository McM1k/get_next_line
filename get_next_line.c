/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:52:53 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/02 23:01:45 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd	new_node(int fd)
{
	t_fd = new;

	new = (t_fd *)ft_memalloc(sizeof(t_fd));
	new->fd = fd;
	new->str = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

static t_fd	is_node_existing(int fd, t_fd *begin)
{
	t_fd	*tmp;
	t_fd	*node;

	tmp = begin;
	node = tmp;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		tmp = node;
		node = node->next;
	}
	node = new_node(fd);
	tmp->next = node;
	return (node);
}

static int	alloc_less(char **line, char **str)
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

static int	reader(int rd, t_fd node, int fd)
{
	char	*buf;
	char	*tmp;

	if (BUFF_SIZE <= 0 || !(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!ft_strchr(node->str, '\n') && rd > 0)
	{
		if ((rd = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if (rd > 0)
		{
			buf[rd] = '\0';
			tmp = node->str;
			node->str = ft_strjoin(tmp, buf);
			ft_strdel(&tmp);
		}
	}
	ft_strdel(&buf);
	return (rd);
}

int			get_next_line(int const fd, char **line)
{
	static t_fd		*start = NULL;
	t_fd			*ptr;
	int				rd;

	if (!start)
		start = new_node(0);
	rd = 1;
	if ((rd = reader(rd, ptr, fd)) == -1)
		return (-1);
	if (!ft_strchr(ptr->str, '\n'))
		*line = ft_strsub(ptr->str, 0, ft_strlen(ptr->str));
	else
		*line = ft_strsub(ptr->str, 0, ft_strchr(ptr->str, '\n') - ptr->str);
	return (0);
}
