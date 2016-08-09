/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:24:46 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 19:40:44 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"

static t_dot	set_eyes_coord(t_fdf *map)
{
	t_dot	eyes;

	eyes.x = WIDTH / 2;
	eyes.y = HEIGHT / 2;
	eyes.z = map->params.eyes_z;
	return (eyes);
}

void			set_proj_coord(t_coord *coord, t_fdf *map)
{
	coord->dotp.x = (map->params.eyes_z * (coord->dot.x - coord->eyes.x)) /
		(map->params.eyes_z + coord->dot.z) + coord->eyes.x;
	coord->dotp.y = (map->params.eyes_z * (coord->dot.y - coord->eyes.y)) /
		(map->params.eyes_z + coord->dot.z) + coord->eyes.y;
	coord->dotp.z = &coord->dot.z;
}

void			mprime(t_fdf *map)
{
	get_range(map);
	map->coord->eyes = set_eyes_coord(map);
	list_mod(map, &set_proj_coord);
	list_mod(map, &set_p_value);
}

