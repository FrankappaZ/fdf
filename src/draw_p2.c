/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:43:17 by abureau           #+#    #+#             */
/*   Updated: 2016/07/06 13:48:30 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		chose_dpne2(t_math *value, t_coord *t_dot)
{
	value->dp = value->dp + value->deltaNE;
	if (t_dot->dotp.x >= t_dot->nexty->dotp.x)
		ft_inctwovar(&value->y, &value->x);
	else
		ft_incdecvar(&value->y, &value->x);
}

static void		chose_dpe2(t_math *value, t_coord *t_dot)
{
	value->dp = value->dp + value->deltaE;
	if (t_dot->dotp.x >= t_dot->nexty->dotp.x)
	{
		if (value->dx >= value->dy)
			value->x++;
		else
			value->y++;
	}
	else
	{
		if (value->dx >= value->dy)
			value->x--;
		else
			value->y++;
	}
}

static void		weirdcase2(t_math *value, t_coord *t_dot, int *p, t_fdf *map)
{
	while (value->y <= t_dot->dotp.y)
	{
		if (value->inv)
			*p = 100 - ((value->y - t_dot->Y1) * 100 / (t_dot->Y3 - t_dot->Y1));
		else
			*p = ((value->y - t_dot->Y1) * 100 / (t_dot->Y3 - t_dot->Y1));
		put_pixel_img(map->win.img, value->x + map->params.hor_pad, ++value->y + map->params.ver_pad, CWHI);
	}
	if (value->inv)
		invert2coord(t_dot);
}

static void		init2draw(t_coord *dot, t_math *value)
{
	if (dot->dotp.x >= dot->nexty->dotp.x)
	{
		value->dx = dot->dotp.x - dot->nexty->dotp.x;
		value->dy = dot->dotp.y - dot->nexty->dotp.y;
	}
	else
	{
		value->dx = dot->nexty->dotp.x - dot->dotp.x;
		value->dy = dot->dotp.y - dot->nexty->dotp.x;
	}
	if (value->dx >= value->dy)
	{
		value->dp = 2 * value->dy - value->dx;
		value->deltaE = 2 * value->dy;
		value->deltaNE = 2 * (value->dy - value->dx);
	}
	else
	{
		value->dp = 2 * value->dx - value->dy;
		value->deltaE = 2 * value->dx;
		value->deltaNE = 2 * (value->dx - value->dy);
	}
	value->x = dot->nexty->dotp.x;
	value->y = dot->nexty->dotp.y;
}

void			drawfcase2(t_coord *t_dot, t_fdf *map)
{
	t_math	value;
	int		p;

	value.inv = 0;
	if (t_dot->Y1 < t_dot->Y3)
	{
		value.inv = 1;
		invert2coord(t_dot);
	}
	init2draw(t_dot, &value);
	while (value.x != t_dot->X1)
	{
		if (value.dp <= 0)
			chose_dpe2(&value, t_dot);
		else
			chose_dpne2(&value, t_dot);
		if (value.inv)
			p = 100 - ((value.x - t_dot->X1) * 100 / (t_dot->X3 - t_dot->X1));
		else
			p = ((value.x - t_dot->X1) * 100 / (t_dot->X3 - t_dot->X1));
		put_pixel_img(map->win.img, value.x + map->params.hor_pad, value.y + map->params.ver_pad, CWHI);
	}
	weirdcase2(&value, t_dot, &p, map);
}
