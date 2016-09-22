/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:28:43 by abureau           #+#    #+#             */
/*   Updated: 2016/09/22 14:43:50 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"
#include <mlx.h>

void		put_pixel_img(void *img, int x, int y, int color)
{
	int		sizu;
	int		endian;
	int		bi;
	int		ipixel;
	t_fdf	*tmp;

	tmp = (t_fdf *)get_data_add(0);
	tmp->params.map = mlx_get_data_addr(img, &bi, &sizu, &endian);
	if (x >= WIDTH + -(tmp->params.imgposx) ||
			y >= HEIGHT + -(tmp->params.imgposy) || x < 0 || y < 0)
		return ;
	bi /= 8;
	ipixel = x * bi + y * sizu;
	tmp->params.map[ipixel] = color >> 0;
	tmp->params.map[ipixel + 1] = color >> 8;
	tmp->params.map[ipixel + 2] = color >> 16;
}

void		print_map_dots(t_fdf *map)
{
	t_coord	*first_elem;
	t_coord	*cursor;

	first_elem = map->coord;
	while (first_elem)
	{
		cursor = first_elem;
		while (cursor)
		{
			put_pixel_img(map->win.img, cursor->dotp.x, cursor->dotp.y,
				get_color(map, cursor->p_val, cursor->dot.z, cursor->dot.z));
			cursor = cursor->nextx;
		}
		first_elem = first_elem->nexty;
	}
}
