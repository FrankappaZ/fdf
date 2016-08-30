/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squaroot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 14:50:54 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/30 14:52:10 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_squaroot(float a)
{
	float	i;
	float	j;
	float	x1;
	float	x2;

	i = 0;
	while ((i * i) < a)
	{
		i += 0.1f;
	}
	x1 = i;
	j = 0;
	while (j < ROOT_P)
	{
		j++;
		x2 = a;
		x2 /= x1;
		x2 += x1;
		x2 /= 2;
		x1 = x2;
	}
	return (x2);
}
