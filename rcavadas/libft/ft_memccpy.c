/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:46:02 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:05:52 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*tmp2;

	tmp = (char*)dst;
	tmp2 = (char*)src;
	i = 0;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		if ((unsigned char)tmp2[i] == (unsigned char)c)
			return ((void*)&tmp[i + 1]);
		i++;
	}
	return (NULL);
}
