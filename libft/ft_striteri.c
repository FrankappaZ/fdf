/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:51:14 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 15:52:10 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	count;

	count = 0;
	if (s != NULL && f != NULL)
	{
		while (*s != '\0')
		{
			f(count, s++);
			count++;
		}
	}
}
