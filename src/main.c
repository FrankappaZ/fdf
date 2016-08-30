/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:30:48 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/30 16:04:28 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	init_ptradr(t_fdf *map)
{
	static int	isinit = 0;

	if (isinit == 0)
	{
		get_data_add((u64)map);
		isinit = 1;
	}
}

static t_fdf	*init_fdf(int fd)
{
	t_fdf	*t_map;
	t_coord	*begin;

	setup_catch();
	begin = NULL;
	t_map = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	ft_bzero(t_map, sizeof(t_fdf));
	t_map->params.rad = RAD;
	t_map->coord = parser(fd, begin);
	t_map->params.spacing = SPACING;
	init_ptradr(t_map);
	mprime(t_map);
	list_mod(t_map, &set_last_elem);
	list_mod(t_map, &map_printer_p);
	init_mlx(t_map);
	return (t_map);
}

int				main(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
	{
		ft_putendl("usage: ./fdf your_map");
		exit(0);
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putendl("FdF failed to open() the map.");
			exit(0);
		}
		else
			init_fdf(fd);
	}
	else
	{
		ft_putendl("Too many arguments given.");
		exit(0);
	}
	return (0);
}
