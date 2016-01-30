/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:37:46 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/30 17:03:32 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include "libft.h"
# define BUFF_SIZE 32
int		get_next_line(int const fd, char **line);
#endif
