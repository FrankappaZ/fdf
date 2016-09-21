/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:03:44 by rcavadas          #+#    #+#             */
/*   Updated: 2016/09/01 12:04:54 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"
#include <signal.h>
#include "../mlx/mlx.h"
#include <stdlib.h>

/*
**prevent ctrl+c for free data before exit
*/

static void	free_def(t_coord *def)
{
	ft_putendl("Free definition :");
	if (def)
	{
		if (def->nextx)
		{
			if (def->nexty->nexty)
				free(def->nexty->nexty);
			if (def->nexty)
				free(def->nexty);
			free(def->nextx);
		}
		free(def);
	}
}

static void	free_mlx(t_fdf *map)
{
	ft_putendl("free mlx :");
	ft_putendl("\tfree img");
	mlx_destroy_image(map->win.mlx, map->win.img);
	ft_putendl("\tfree win");
	free(map->win.win);
	ft_putendl("\tfree mlx");
	free(map->win.mlx);
}

void		free_data_list(void)
{
	t_fdf		*map;
	static int	isok = 0;

	ft_putendl("free data begin");
	if (isok)
		exit(0);
	map = (t_fdf *)get_data_add(0);
	if (map)
	{
		if (map->coord)
			list_mod(map, free_elem);
		ft_putendl("free_data_mlx");
		if (map->defcoord)
			free_def(map->defcoord);
		free_mlx(map);
	}
	if (map)
	isok = 1;
	exit(0);
}

static void	sig_handler(int signo)
{
	ft_putendl("sig catch");
	if (signo == SIGINT)
	{
		ft_putendl("ctrl+c protection, all item free and exit");
		free_data_list();
	}
	if (signo == SIGSEGV)
	{
		ft_putendl("Segfault Protection !, all item free and exit");
		free_data_list();
	}
	if (signo == SIGABRT)
	{
		ft_putendl("SIGABRT Protection !, all item free and exit");
		exit(0);
	}
}

void		setup_catch(void)
{
	if (signal(SIGSEGV, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
	if (signal(SIGABRT, sig_handler) == SIG_ERR)
		ft_putendl("error while catching signal\n");
}
