/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:53:09 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 15:52:48 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tronc;
	unsigned int	tmpstart;
	unsigned int	i;

	i = 0;
	tmpstart = start + len;
	tronc = (char *)malloc(sizeof(char) * len + 1);
	if (!tronc || !s)
	{
		if (!tronc)
			free(tronc);
		return (NULL);
	}
	while (start != tmpstart)
	{
		tronc[i] = s[start];
		start++;
		i++;
	}
	tronc[i] = '\0';
	return (tronc);
}
