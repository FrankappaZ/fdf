/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 14:09:22 by abureau           #+#    #+#             */
/*   Updated: 2016/08/30 15:29:08 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"

void	free_elem(t_coord *elem, t_fdf *map)
{
	if (map)
	{
		if (elem->nextx)
			elem->nextx = NULL;
		if (elem->nexty)
			elem->nexty = NULL;
		ft_putendl("free(elem)");
		free(elem);
		elem = NULL;
	}
}

void	count_elem(t_coord *elem, t_fdf *map)
{
	if (elem)
		map->params.z_range.nb_elem++;
	else
		ft_putendl("elem error in list_func.c:count_elem");
}

t_coord	*get_last_elem(t_coord *elem)
{
	static t_coord *lastelem = NULL;

	if (elem)
		lastelem = elem;
	return (lastelem);
}

void	set_last_elem(t_coord *elem, t_fdf *map)
{
	if (map)
		if (!elem->nextx)
			if (!elem->nexty)
				if (elem)
					get_last_elem(elem);
}
