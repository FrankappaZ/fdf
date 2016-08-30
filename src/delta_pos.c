/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 12:38:25 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/30 14:53:00 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	dx_inf_dy(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	delta_case_0(math);
	while ((math->x0 = math->x0 - 1) != math->x1)
	{
		put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
			get_dist(math->x0, math->y0, math->x1, math->y1)
			* 100 / math->dist, dot0->dot.z, dot1->dot.z));
		if ((math->e = math->e - math->dy) >= 0)
		{
			math->y0 = math->y0 - 1;
			math->e = math->e + math->dx;
		}
	}
}

void	dx_sup_dy(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	delta_case_0(math);
	while ((math->x0 = math->x0 + 1) != math->x1)
	{
		put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
			get_dist(math->x0, math->y0, math->x1, math->y1)
			* 100 / math->dist, dot0->dot.z, dot1->dot.z));
		if ((math->e = math->e - math->dy) < 0)
		{
			math->y0 = math->y0 + 1;
			math->e = math->e + math->dx;
		}
	}
}

void	dx_sup_mdy(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	delta_case_0(math);
	while ((math->x0 = math->x0 + 1) != math->x1)
	{
		put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
			get_dist(math->x0, math->y0, math->x1, math->y1)
			* 100 / math->dist, dot0->dot.z, dot1->dot.z));
		if ((math->e = math->e + math->dy) < 0)
		{
			math->y0 = math->y0 - 1;
			math->e = math->e + math->dx;
		}
	}
}

void	mdx_sup_dy(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	delta_case_0(math);
	while ((math->x0 = math->x0 - 1) != math->x1)
	{
		put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
			get_dist(math->x0, math->y0, math->x1, math->y1)
			* 100 / math->dist, dot0->dot.z, dot1->dot.z));
		if ((math->e = math->e + math->dy) >= 0)
		{
			math->y0 = math->y0 + 1;
			math->e = math->e + math->dx;
		}
	}
}
