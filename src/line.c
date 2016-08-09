/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 16:08:51 by abureau           #+#    #+#             */
/*   Updated: 2016/08/09 19:52:23 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	drawfunc(t_fdf *map)
{
	t_coord	*tmp;
	t_coord	*cursorx;

	cursorx = map->coord;
	while (cursorx != NULL)
	{
		tmp = cursorx;
		cursorx = cursorx->nexty;
		while (tmp != NULL)
		{
			if (tmp->nextx)
				draw_segment(map, tmp->dotp, tmp->nextx->dotp);
			if (tmp->nexty)
				draw_segment(map, tmp->dotp, tmp->nexty->dotp);
			tmp = tmp->nextx;
		}
	}
}

int		invertcoord(t_coord *t_dot)
{
	int	tmpxa;
	int	tmpya;
	int	tmpxb;
	int	tmpyb;

	tmpxa = t_dot->dotp.x;
	tmpya = t_dot->dotp.y;
	tmpxb = t_dot->nextx->dotp.x;
	tmpyb = t_dot->nextx->dotp.y;
	t_dot->dotp.x = tmpxb;
	t_dot->dotp.y = tmpyb;
	t_dot->nextx->dotp.x = tmpxa;
	t_dot->nextx->dotp.y = tmpya;
	return (0);
}

int		invert2coord(t_coord *t_dot)
{
	int	tmpxa;
	int	tmpya;
	int	tmpxb;
	int	tmpyb;

	tmpxa = t_dot->dotp.x;
	tmpya = t_dot->dotp.y;
	tmpxb = t_dot->nexty->dotp.x;
	tmpyb = t_dot->nexty->dotp.y;
	t_dot->dotp.x = tmpxb;
	t_dot->dotp.y = tmpyb;
	t_dot->nexty->dotp.x = tmpxa;
	t_dot->nexty->dotp.y = tmpya;
	return (0);
}
