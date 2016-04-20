/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:52:28 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 15:52:38 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

char	*ft_strnew(size_t size)
{
	char				*s;
	unsigned int		i;

	i = 0;
	s = (char*)malloc(sizeof(char) * (size + 1));
	if (s)
	{
		while (i < size)
		{
			s[i] = '\0';
			i++;
		}
		s[i] = '\0';
		return (s);
	}
	else
		return (NULL);
}
