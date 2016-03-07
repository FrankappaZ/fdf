/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:53:19 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:03:47 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strtrimchar(char const *s, char c)
{
	int		len;
	int		i;
	int		j;
	char	*strim;

	ft_inittwovar(&i, &j);
	len = ft_strlen(s);
	while (s[len - 1] == c)
	{
		len--;
		if (len == 0)
			return (NULL);
	}
	while (s[i] == c)
	{
		len--;
		i++;
	}
	strim = ft_strnew(len);
	while (j != len)
	{
		strim[j] = s[i];
		ft_inctwovar(&i, &j);
	}
	return (strim);
}
