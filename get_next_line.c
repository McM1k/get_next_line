/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 19:52:53 by gboudrie          #+#    #+#             */
/*   Updated: 2016/02/03 21:14:34 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//static void	*ft_addalloc(char **line, char *buf, int len)
//{
//	char	*new_line;
//
//	new_line = ft_strnew(ft_strlen(*line) + len - 1);
//	strcpy(new_line, *line);
//	strncat(new_line, buf, len - 1);
//	free(*line);
//	line = &new_line;
//	return (line);
//}

int			get_next_line(int const fd, char ** line)
{
	static char		*str = NULL;
	char			buf[BUFF_SIZE];
	int				rd;
	char			*tmp;

	if (!str) // when you need to refill str
	{
		rd = read(fd, buf, BUF_SIZE);
		if (rd) // dont create an empty line if eof
			str = ft_strsub(buf, 0, rd);
	}
	while (read(fd, buf, BUF_SIZE) && !(ft_strchr(str, '\n')))
	{	
		tmp = str;
		str = ft_strjoin(tmp, buf);
		free(&tmp);
	}
	if (ft_strchr(str, '\n')) // if we get a newLine
	{
		line = ft_strsub(str, 0, ft_strchr(str, '\n') - str);
		tmp = str;
		str = ft_strsub(tmp, ft_strchr(str, '\n') - str, ft_strlen(tmp));
		free(&tmp);
		return (1);
	}
	if (!(str) && !(read(fd, buf, BUF_SIZE))) // if str=null & rd=0 , it's over
		return (0);








//	while ((rd = read(fd, buf, BUF_SIZE)) > 0 )
//	{
//		if (!(ft_strchr(buf, '\n')))
//			len = rd;
//		else
//			len = ft_strchr(buf, '\n') - buf;
//		if (str)
//			str = ft_addalloc(&str, buf, len);
//		else
//			str = ft_strsub(buf, 0, rd);
//		if (len < rd || rd == 0) //if eof or \n
//		{
//			
//
//
//		}
//	}
//	if (rd < 1)
//		return (rd);
//	return (1);
}
