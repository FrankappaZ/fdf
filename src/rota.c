/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 16:35:06 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 16:36:03 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>

void		map_rotation(t_coord *elem, t_fdf *map)
{
	t_dotp	tmp_dot;

	tmp_dot = elem->dotp;
	elem->dotp.x = (tmp_dot.x * cos(map->params.rad))
		- (tmp_dot.y * sin(map->params.rad));
	elem->dotp.y = (tmp_dot.y * cos(map->params.rad))
		+ (tmp_dot.x * sin(map->params.rad));
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

	first_elem = map->coord;
	while (first_elem)
	{
		cursor = first_elem;
		while (cursor)
		{
			ptr_func(cursor, map);
			cursor = cursor->nextx;
		}
		first_elem = first_elem->nexty;
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
