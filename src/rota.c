/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 16:35:06 by rcavadas          #+#    #+#             */
/*   Updated: 2016/09/02 15:28:06 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void		map_rotation(t_coord *elem, t_fdf *map)
{
	int	dist;
	t_dot	center;

	center = get_center(map);
	dist = (int)get_dist(center.x, center.y, elem->dot.x, elem->dot.y);
	if (dist < 0)
	{
		ft_putstrnb("dist : ", dist);
		ft_putstrnb("0*0 : ", 0.*0.);
		ft_putstrnb("elem.x : ", elem->dot.x);
		ft_putstrnb("elem.y : ", elem->dot.y);
	}
	if (map)
		if (elem)
		{
			if ((center.x == elem->dot.x) && (center.y == elem->dot.y))
				return;
				elem->dot.x = dist * cos(map->params.rad) + center.x;
				elem->dot.y = dist * sin(map->params.rad) + center.y;
		}
}

void		map_printer_p(t_coord *elem, t_fdf *map)
{
	static int	cnt = 0;

	ft_putnbr(cnt);
	ft_putstr(" :: ");
	ft_putstr("x : ");
	ft_putnbr(elem->dotp.x);
	ft_putstr(" | y : ");
	ft_putnbrnl(elem->dotp.y);
	cnt++;
	if (map == NULL)
		map = NULL;
}

void		map_printer(t_coord *elem, t_fdf *map)
{
	static int	cnt = 0;

	ft_putnbr(cnt);
	ft_putstr(" :: ");
	ft_putstr("x : ");
	ft_putnbr(elem->dot.x);
	ft_putstr(" | y : ");
	ft_putnbr(elem->dot.y);
	ft_putstr(" | z : ");
	ft_putnbr(elem->dot.z);
	ft_putstr(" = ");
	ft_putnbr(elem->p_val);
	ft_putstr(" % \n");
	cnt++;
	if (map == NULL)
		map = NULL;
}

void		list_mod(t_fdf *map, void (*ptr_func)(t_coord*, t_fdf*))
{
	t_coord	*first_elem;
	t_coord	*cursor;
	t_coord	*tmpx;

	first_elem = map->coord;
	while (first_elem)
	{
		cursor = first_elem;
		first_elem = first_elem->nexty;
		while (cursor)
		{
			tmpx = cursor->nextx;
			ptr_func(cursor, map);
			cursor = tmpx;
		}
	}
}

void		set_p_value(t_coord *elem, t_fdf *map)
{
	if (map->RANGE != 0)
		elem->p_val = ((elem->dot.z - map->LOW_RANGE) * 100 / (map->HIGH_RANGE -
		map->LOW_RANGE));
	else
		elem->p_val = 0;
}
