/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:46:21 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:05:47 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char*)dst;
	tmp2 = (char*)src;
	i = 0;
	while (n != i)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dst);
}
