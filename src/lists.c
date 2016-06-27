/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 18:08:47 by rcavadas          #+#    #+#             */
/*   Updated: 2016/06/27 19:20:13 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_coord	*create_coord(t_dot dot)
{
	t_coord	*elem;

	elem = (t_coord*) ft_memalloc(sizeof(t_coord));
	ft_bzero(elem, sizeof(t_coord));
	elem->dot = dot;
	return (elem);
}

t_coord	*addlst(t_coord *begin, t_dot dot)
{
	int		y;
	t_coord	*elem;
	t_coord	*tmp;

	y = 0;
	elem = create_coord(dot);
	tmp = begin;
	if (!begin)
		return (elem);
	else if (elem)
	{
		while (dot.y != y++)
			tmp = tmp->nexty;
		if (tmp)
		{
			while (tmp->nextx != NULL)
				tmp = tmp->nextx;
			tmp->nextx = elem;
		}
		else
			tmp = elem;
	}
	return (begin);
}
