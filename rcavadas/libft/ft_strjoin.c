/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:51:20 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:04:57 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	i = 0;
	if (s1)
		i += i + ft_strlen(s1);
	if (s2)
		i += i + ft_strlen(s2);
	res = ft_strnew(i);
	if (!res)
		return (NULL);
	if (s1)
		res = ft_strcat(res, s1);
	if (s2)
		res = ft_strcat(res, s2);
	return (res);
}
