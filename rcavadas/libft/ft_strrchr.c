/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:52:52 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:04:26 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	lens;

	lens = ft_strlen(s) + 1;
	if (c == 0)
		return ((char *)&s[lens] - 1);
	while (lens >= 0)
	{
		if (s[lens] == (char)c)
		{
			return ((char *)&s[lens]);
		}
		lens--;
	}
	return (NULL);
}
