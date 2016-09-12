/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:24:46 by rcavadas          #+#    #+#             */
/*   Updated: 2016/09/12 17:11:04 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"

static void	set_eyes_coord(t_fdf *map)
{
	static int	isok = 0;
	t_dot		center;

	ft_bzero(&center, sizeof(center));
	if (!isok)
	{
		ft_putendl("set_eyes_coord");
		map->params.eyes.x = -(HEIGHT / 2);
		map->params.eyes.y = -(WIDTH / 2);
		map->params.eyes.z = 100;
		isok = 1;
	}
	else if (isok == 1)
	{
		ft_putendl("reset_eyes_coord");
		ft_putnbr(get_center(map).x);
		ft_putnbr(get_center(map).y);
		map->params.eyes.x = center.x;
		map->params.eyes.y = center.y;
		isok = 2;
	}
}

 void	center_eyes(t_fdf *map)
{
	set_eyes_coord(map);

}

void		set_proj_coord(t_coord *coord, t_fdf *map)
{
	int	sec_div;
	int fd;
	char rnd;

	rnd = 0;
	fd = open("/dev/urandom",  O_RDONLY);
	read(fd, &rnd, 1 );
	
	if (map->params.gol_start)
	{

		if ( rnd % 3 == 0)
			coord->dot.z = 0;
		else if (rnd % 3 == 1)
			coord->dot.z = map->HIGH_RANGE / 2;
		else
			coord->dot.z = map->HIGH_RANGE;
	}
	close(fd);
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
