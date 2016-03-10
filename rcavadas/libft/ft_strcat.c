/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:50:18 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/08 18:43:17 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char *s1iter;

	s1iter = s1;
	while (*s1iter != '\0')
		s1iter++;
	while (*s2 != '\0')
		*s1iter++ = *s2++;
	*s1iter = '\0';
	return (s1);
}
