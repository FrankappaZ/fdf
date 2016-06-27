/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:30:48 by rcavadas          #+#    #+#             */
/*   Updated: 2016/06/27 19:20:10 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	init_fdf(int fd)
{
	t_fdf	*t_map;

	t_map = (t_fdf*) ft_memalloc(sizeof(t_fdf));
	ft_bzero(t_map, sizeof(t_fdf));
	t_map->coord = parser(fd);
}

int	main(int argc, char **argv)
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
}
