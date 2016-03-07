/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:46:43 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:05:40 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memset(void *s, int c, size_t len)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	if (len == 0)
		return (str);
	while (count < len)
	{
		str[count] = (unsigned char)c;
		count++;
	}
	return (s);
}
