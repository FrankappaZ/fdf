/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:50:30 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 19:54:06 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	init_math(t_math *math, t_coord *dot0, t_coord *dot1)
{
	math->x0 = dot0->dotp.x;
	math->y0 = dot0->dotp.y;
	math->x1 = dot1->dotp.x;
	math->y1 = dot1->dotp.y;
	math->e = 0;
}

static void	dx_positive(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if ((math->dy = math->y1 - math->y0) != 0)
	{
		if (math->dy > 0)
			bres_case_0(math, map, dot0, dot1);
		else
			bres_case_1(math, map, dot0, dot1);
	}
	else
		while ((math->x0 = math->x0 + 1) != math->x1)
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
}

void		draw_segment(t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	t_math	math;

	init_math(&math, dot0, dot1);
	if ((math.dx = math.x0 - math.x1) != 0)
	{
		if (math.dx > 0)
			dx_positive(&math, map, dot0, dot1);
		else
		{
			if ((math.dy = math.y1 - math.y0) != 0)
			{
				if (math.dy > 0)
					bres_case_2(&math, map, dot0, dot1);
				else
					bres_case_3(&math, map, dot0, dot1);
			}
			else
				while ((math.x0 = math.x0 - 1) != math.x1)
					ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
		}
	}
	else
		bres_case_4(&math, map, dot0, dot1);
}

void		start_draw(t_fdf *map)
{
	t_coord	*tmp;
	t_coord	*cursory;

	cursory = map->coord;
	while (cursory != NULL)
	{
		tmp = cursory;
		cursory = cursory->nexty;
		while (tmp != NULL)
		{
			if (tmp->nextx)
				draw_segment(map, tmp, tmp->nextx);
			if (tmp->nexty)
				draw_segment(map, tmp, tmp->nexty);
			tmp = tmp->nextx;
		}
	}
}
