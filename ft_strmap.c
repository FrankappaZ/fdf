/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:51:50 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 15:52:23 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s));
	if (s != NULL && f != NULL && tmp != NULL)
	{
		while (i != ft_strlen(s))
		{
			tmp[i] = f(s[i]);
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
