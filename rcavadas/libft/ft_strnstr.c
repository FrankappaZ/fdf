/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:52:42 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:04:28 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	char			*str;

	str = ft_strnew(n);
	str = ft_strncpy(str, s1, n + 1);
	i = 0;
	if ((ft_strlen(s1) == 0) && (ft_strlen(s2) > 0))
		return (NULL);
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	if (ft_strlen(s1) == 0)
		return ((char*)s2);
	while (s1[i] != '\0' && i < n)
	{
		if (ft_strncmp(&str[i], s2, ft_strlen(s2)) == 0)
			return ((char*)&s1[i]);
		i++;
		if (i >= n)
			return (NULL);
	}
	return (NULL);
}
