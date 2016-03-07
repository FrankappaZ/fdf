/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:53:14 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:03:50 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	size_t	ft_lenght(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (!s[i])
		return (0);
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
	{
		j--;
		i++;
	}
	return (ft_strlen(s) - i);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = NULL;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		new = ft_strnew(sizeof(*new) * (ft_lenght(s)));
		if (!new)
			return (NULL);
		while (j < ft_lenght(s))
		{
			new[j] = s[i];
			i++;
			j++;
		}
	}
	return (new);
}
