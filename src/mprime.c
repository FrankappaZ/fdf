/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:24:46 by rcavadas          #+#    #+#             */
/*   Updated: 2016/06/29 15:29:19 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	mprime(t_fdf *map)
{
	t_coord	*first_elem;
	t_coord	*cursor;

	first_elem = map->coord;
	while (first_elem)
	{
		cursor = first_elem;
		while (cursor->nextx)
		{
			cursor->dotp.xp = (1 / sqrt(2)) * (cursor->dot.x - cursor->dot.y);
			cursor->dotp.yp = (sin(map->params.radius) / sqrt(2)) *
				(cursor->dotp.xp + cursor->dotp.yp) + cursor->dot.z *
				cos(map->params.radius);
			cursor = cursor->nextx;
		}
		first_elem = first_elem->nexty;
	}
}
