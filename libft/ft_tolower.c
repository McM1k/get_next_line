/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:34:09 by gboudrie          #+#    #+#             */
/*   Updated: 2015/11/25 20:36:44 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}