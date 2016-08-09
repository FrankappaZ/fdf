/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 16:25:01 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 20:10:13 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		get_range(t_fdf *map)
{
	t_coord	*tmp;
	t_coord	*cursorx;

	if (!map)
		exit(0);
	map->LOW_RANGE = map->coord->dot.z;
	map->HIGH_RANGE = map->coord->dot.z;
	cursorx = map->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		while (tmp != NULL)
		{
			if (tmp->dot.z < map->LOW_RANGE)
				map->LOW_RANGE = tmp->dot.z;
			else if (tmp->dot.z > map->HIGH_RANGE)
				map->HIGH_RANGE = tmp->dot.z;
			tmp = tmp->nexty;
		}
		cursorx = cursorx->nextx;
	}
	map->RANGE = map->HIGH_RANGE - map->LOW_RANGE;
}

static int	color_chose(double p_now)
{
	if (p_now == 0)
		return (CWHI);
	else if (p_now <= 20)
	{
		return (CWHI - (RP0 << 16) - (RP0 << 8));
	}
	else if (p_now <= 40)
	{
		return (CBLU + (RP20 << 8));
	}
	else if (p_now <= 60)
	{
		return (CCYA - (RP40));
	}
	else if (p_now <= 80)
	{
		return (CGRE + (RP60 << 16));
	}
	else
	{
		return (CYEL - (RP80 << 8));
	}
}

void		draw_pix(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	int		color;
	float	dist;
	int		p;

	dist = ;
	p = 100 - ()
	color = 0;
	if(dot0->dotp->z > dot1->dotp->z)
	
	put_pixel_img(map->win.img, math->x0, math->y0, CGRE);
}

int			get_color(t_fdf *map, int p_beg, int value, int next)
{
	double	p_start;
	double	p_now;
	double	p_end;

	if (value == next)
	{
		if (map->RANGE != 0)
			p_start = (value - map->LOW_RANGE) * 100 / map->RANGE;
		else
			p_start = (value - map->LOW_RANGE) * 100 / 1;
		p_now = p_start;
		p_beg = p_start;
	}
	else
	{
		p_start = (value - map->LOW_RANGE) * 100 / map->RANGE;
		p_end = (next - map->LOW_RANGE) * 100 / map->RANGE;
		p_now = p_start + (p_beg * ((p_end - p_start) / 100));
	}
	return (color_chose(p_now));
}
