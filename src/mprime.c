/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:24:46 by rcavadas          #+#    #+#             */
/*   Updated: 2016/06/29 18:53:34 by rcavadas         ###   ########.fr       */
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
			cursor->dotp.x = (1 / sqrt(2)) * (cursor->dot.x - cursor->dot.y);
			cursor->dotp.y = (sin(map->params.rad) / sqrt(2)) *
				(cursor->dotp.x + cursor->dotp.y) + cursor->dot.z *
				cos(map->params.rad);
			cursor->dotp.x += map->params.hor_pad;
			cursor->dotp.y += map->params.ver_pad;
			cursor = cursor->nextx;
		}
		first_elem = first_elem->nexty;
	}
}
