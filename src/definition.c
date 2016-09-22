/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:07:37 by abureau           #+#    #+#             */
/*   Updated: 2016/09/22 15:08:36 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <mlx.h>

static t_coord	*creat_coord(t_dot dot)
{
	t_coord	*elem;

	elem = (t_coord*)ft_memalloc(sizeof(t_coord));
	ft_bzero(elem, sizeof(t_coord));
	elem->dotp.x = dot.x;
	elem->dotp.y = dot.y;
	elem->dot.z = dot.z;
	return (elem);
}

static t_dot	defdot(int x, int y, int z)
{
	t_dot	new_dot;

	new_dot.x = x;
	new_dot.y = y;
	new_dot.z = z;
	ft_putstrnb("z value creat dot", z);
	return (new_dot);
}

static void		switch_img(t_fdf *map)
{
	void	*tmp;

	tmp = map->win.img;
	map->win.img = map->win.defimg;
	map->win.defimg = tmp;
}

void			draw_def(t_fdf *map)
{
	t_coord *def;

	switch_img(map);
	def = NULL;
	if (map)
		def = map->defcoord;
	else
		return ;
	if (def->nextx)
		draw_segment(map, def, def->nextx);
	if (def->nexty)
	{
		draw_segment(map, def, def->nexty);
		mlx_string_put(map->win.mlx, map->win.win, WIDTH - WIDTHD - 30, 30,
				CWHI, ft_itoa(map->LOW_RANGE));
	}
	if (def->nexty->nextx)
		draw_segment(map, def->nextx, def->nextx->nexty);
	if (def->nextx->nexty)
	{
		draw_segment(map, def->nexty, def->nextx->nexty);
		draw_segment(map, def->nextx, def->nexty);
		draw_segment(map, def, def->nextx->nexty);
	}
	switch_img(map);
}

t_coord			*init_def_coord(t_fdf *map)
{
	t_coord *begdef;

	begdef = creat_coord(defdot(0, 0, map->LOW_RANGE));
	begdef->nextx = creat_coord(defdot(WIDTHD, 0, map->LOW_RANGE));
	begdef->nexty = creat_coord(defdot(0, HEIGHTD, map->HIGH_RANGE));
	begdef->nextx->nexty = creat_coord(defdot(WIDTHD, HEIGHTD,
													map->HIGH_RANGE));
	begdef->nexty->nextx = begdef->nextx->nexty;
	return (begdef);
}
