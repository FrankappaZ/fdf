/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:30:48 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 16:29:03 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"
#include "../mlx/mlx.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	init_ptradr(t_fdf *map)
{
	static int	isinit = 0;
	int		fd_add;

	if (isinit == 0)
	{
		fd_add = open("./address", O_CREAT | O_RDWR | O_TRUNC);
		write(fd_add, ft_lltoabase((u64)map, 10, 0), sizeof(long));
		close(fd_add);
//		ft_memset(&map->params.z_range, map->coord->dot.z, sizeof(map->params.z_range));
//		map->params.z_range.nb_elem = 0;
//		list_mod(map, &count_elem);
//		list_mod(map, &get_range);
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
	t_map->params.eyes_z = 100;
	init_ptradr(t_map);
	mprime(t_map);
	list_mod(t_map, &map_printer);
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
