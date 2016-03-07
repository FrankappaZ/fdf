/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:50:23 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:05:11 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (i > 0)
	{
		while (s != '\0')
		{
			if (*s == (char)c)
				return ((char *)s);
			if (i == 0)
				return (NULL);
			i--;
			s++;
		}
	}
	return (NULL);
}
