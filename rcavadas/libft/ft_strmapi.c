/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:51:55 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:04:45 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = NULL;
	if (s && f)
	{
		tmp = ft_strnew(ft_strlen(s));
		if (!tmp)
			return (NULL);
		while (s[i])
		{
			tmp[i] = f(i, s[i]);
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
