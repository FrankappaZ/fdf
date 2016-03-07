/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:46:09 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:05:50 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char*)s;
	while (n != i)
	{
		if ((unsigned char)tmp[i] == (unsigned char)c)
			return ((void*)&(tmp[i]));
		i++;
	}
	return (NULL);
}
