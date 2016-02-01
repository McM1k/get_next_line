/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:37:46 by gboudrie          #+#    #+#             */
/*   Updated: 2016/02/01 22:19:07 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include "libft.h"
# define BUFF_SIZE 32
# define MAX_FD 2147483647
int		get_next_line(int const fd, char **line);
#endif
