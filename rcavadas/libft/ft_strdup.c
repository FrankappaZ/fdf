/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:50:56 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:05:03 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dest)
	{
		ft_strcpy(dest, s1);
		return (dest);
	}
	return (NULL);
}
