/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 18:08:47 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 16:28:19 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_coord	*create_coord(t_dot dot)
{
	t_coord	*elem;

	elem = (t_coord*)ft_memalloc(sizeof(t_coord));
	ft_bzero(elem, sizeof(t_coord));
	elem->dot = dot;
	return (elem);
}

t_coord			*addlst(t_coord *begin, t_dot dot)
{
	int		y;
	t_coord	*elem;
	t_coord	*tmp;

	y = 0;
	elem = create_coord(dot);
	tmp = begin;
	if (begin == NULL)
		return (elem);
	while (tmp->nexty != NULL && dot.y-- >= 0)
		tmp = tmp->nexty;
	if (dot.y > 0 && tmp->nexty == NULL)
	{
		tmp->nexty = elem;
		return (begin);
	}
	while (tmp->nextx != NULL)
		tmp = tmp->nextx;
	tmp->nextx = elem;
	return (begin);
}

void			linker(t_coord *begin)
{
	t_coord	*first_elem;
	t_coord	*actual_y;
	t_coord	*y_plus_1;

	first_elem = begin;
	actual_y = begin;
	y_plus_1 = begin->nexty;
	while (begin && actual_y->nexty)
	{
		while (actual_y->nextx && y_plus_1->nextx)
		{
			actual_y = actual_y->nextx;
			y_plus_1 = y_plus_1->nextx;
			actual_y->nexty = y_plus_1;
		}
		first_elem = first_elem->nexty;
		actual_y = first_elem;
		y_plus_1 = actual_y->nexty;
	}
}

void			coord_setter(t_coord *begin)
{
	t_coord	*first_elem;
	t_coord	*cursor;
	t_dot	counters;

	first_elem = begin;
	counters.x = 0;
	counters.y = 0;
	while (first_elem)
	{
		cursor = first_elem;
		while (cursor->nextx)
		{
			cursor->dot.x = counters.x++ * SPACING;
			cursor->dot.y = counters.y * SPACING;
			cursor = cursor->nextx;
		}
		cursor->dot.x = counters.x++ * SPACING;
		cursor->dot.y = counters.y * SPACING;
		first_elem = first_elem->nexty;
		counters.x = 0;
		counters.y++;
	}
}

void			map_explorer(t_coord *begin)
{
	t_coord	*first_elem;
	t_coord	*cursor;

	first_elem = begin;
	while (first_elem)
	{
		cursor = first_elem;
		while (cursor)
		{
			ft_putnbr(cursor->dotp.x);
			ft_putchar(' ');
			ft_putnbr(cursor->dotp.y);
			ft_putchar(' ');
			cursor = cursor->nextx;
		}
		first_elem = first_elem->nexty;
		ft_putchar('\n');
	}
}
