/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:46:33 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:05:43 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmpdest;
	char	*tmpsrc;
	size_t	i;

	i = 0;
	tmpsrc = (char*)src;
	tmpdest = (char*)dst;
	if (tmpdest > tmpsrc)
	{
		tmpdest += len;
		tmpsrc += len;
		while (i < len)
		{
			*--tmpdest = *--tmpsrc;
			i++;
		}
	}
	else
		while (i < len)
		{
			tmpdest[i] = tmpsrc[i];
			i++;
		}
	return (tmpdest);
}
