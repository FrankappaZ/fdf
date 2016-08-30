/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:24:46 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/30 15:31:23 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"

static void	set_eyes_coord(t_fdf *map)
{
	ft_putendl("set_eyes_coord");
	map->params.eyes.x = -(HEIGHT / 2);
	map->params.eyes.y = -(WIDTH / 2);
	map->params.eyes.z = 50;
}

void		set_proj_coord(t_coord *coord, t_fdf *map)
{
	int	sec_div;

	sec_div = (map->params.eyes.z + coord->dot.z);
	if (sec_div <= 0)
		sec_div = 1;
	coord->dotp.x = (map->params.eyes.z * (coord->dot.x - map->params.eyes.x)) /
	sec_div + map->params.eyes.x;
	coord->dotp.y = (map->params.eyes.z * (coord->dot.y - map->params.eyes.y)) /
	sec_div + map->params.eyes.y;
}

void		mprime(t_fdf *map)
{
	static int	isset = 0;

	if (!isset)
	{
		get_range(map);
		set_eyes_coord(map);
		isset = 1;
	}
	if (map->params.eyes.z <= 0)
		map->params.eyes.z = 1;
	list_mod(map, &set_proj_coord);
	list_mod(map, &set_p_value);
}
