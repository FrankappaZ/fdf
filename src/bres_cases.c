/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 20:06:27 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 20:06:28 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*

			put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
						get_dist(math->x0, math->y0, math->x1, math->y1) 
						* 100 /	math->dist, dot0->dotp.z, dot1->dotp.z));
*/


/*	vecteur diagonal ou oblique proche horizontal 1er octant*/
static void	dx_sup_dy(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
		delta_case_0(math);
		while ((math->x0 = math->x0 + 1) != math->x1)
		{
			put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
				get_dist(math->x0, math->y0, math->x1, math->y1) 
				* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
			if ((math->e = math->e - math->dy) < 0)
			{
				math->y0 = math->y0 + 1;
				math->e = math->e + math->dx;
			}
		}

}


void	bres_case_0(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if (math->dx >= math->dy)	
		dx_sup_dy(math, map, dot0, dot1);
	else
	{
		delta_case_1(math);
		while ((math->y0 = math->y0 + 1) != math->y1)
		{
			put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
				get_dist(math->x0, math->y0, math->x1, math->y1) 
				* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
			if ((math->e = math->e - math->dx) < 0)
			{
				math->x0 = math->x0 + 1;
				math->e = math->e + math->dy;
			}
		}
	}
}

static void	dx_sup_mdy(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	delta_case_0(math);
	while ((math->x0 = math->x0 + 1) != math->x1)
	{
		put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
			get_dist(math->x0, math->y0, math->x1, math->y1) 
			* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
		if ((math->e = math->e + math->dy) < 0)
		{
			math->y0 = math->y0 - 1;
			math->e = math->e + math->dx;
		}
	}

}

void	bres_case_1(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if (math->dx >= -(math->dy))
		dx_sup_mdy(math, map, dot0, dot1);
	else
	{
		delta_case_1(math);
		while ((math->y0 = math->y0 + 1) == math->y1)
		{
			put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
				get_dist(math->x0, math->y0, math->x1, math->y1) 
				* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
			if ((math->e = math->e + math->dx) > 0)
			{
				math->x0 = math->x0 + 1;
				math->e = math->e + math->dy;
			}
		}
	}
}

static void	mdx_sup_dy(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	delta_case_0(math);
	while ((math->x0 = math->x0 - 1) != math->x1)
	{
		put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
			get_dist(math->x0, math->y0, math->x1, math->y1) 
			* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
		if ((math->e = math->e + math->dy) >= 0)
		{
			math->y0 = math->y0 + 1;
			math->e = math->e + math->dx;
		}
	}

}

void	bres_case_2(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if (-(math->dx) >= math->dy)
		mdx_sup_dy(math, map, dot0, dot1);
	else
	{
		delta_case_1(math);
		while ((math->y0 = math->y0 + 1) != math->y1)
		{
			put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
				get_dist(math->x0, math->y0, math->x1, math->y1) 
				* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
			if ((math->e = math->e + math->dx) <= 0)
			{
				math->x0 = math->x0 - 1;
				math->e = math->e + math->dy;
			}
		}
	}
}

static void	dx_inf_dy(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
		delta_case_0(math);
		while ((math->x0 = math->x0 - 1) != math->x1)
		{
			put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
				get_dist(math->x0, math->y0, math->x1, math->y1) 
				* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
			if ((math->e = math->e - math->dy) >= 0)
			{
				math->y0 = math->y0 - 1;
				math->e = math->e + math->dx;
			}
		}

}

void	bres_case_3(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if (math->dx <= math->dy)
		dx_inf_dy(math,  map, dot0, dot1);
	else
	{
		delta_case_1(math);
		while ((math->y0 = math->y0 - 1) != math->y1)
		{
			put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
				get_dist(math->x0, math->y0, math->x1, math->y1) 
				* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
			if ((math->e = math->e - math->dx) >= 0)
			{
				math->x0 = math->x0 - 1;
				math->e = math->e + math->dy;
			}
		}
	}
}

void	bres_case_4(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if ((math->dy = math->y1 - math->y0) != 0)
	{
		if (math->dy > 0)
			while ((math->y0 = math->y0 + 1) != math->y1)
			{			
				put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
					get_dist(math->x0, math->y0, math->x1, math->y1) 
					* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
			}
	}
	else
	{
		while ((math->y0 = math->y0 - 1) != math->y1)
		{
			put_pixel_img(map->win.img, math->x0, math->y0, get_color(map,
				get_dist(math->x0, math->y0, math->x1, math->y1) 
				* 100 /	math->dist, dot0->dot.z, dot1->dot.z));
		}
	}
}
