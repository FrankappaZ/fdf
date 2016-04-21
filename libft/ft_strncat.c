/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:52:00 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 15:52:29 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	s1[ft_strlen(s1) + n] = '\0';
	ft_strncpy(&s1[ft_strlen(s1)], s2, n);
	return (s1);
}
