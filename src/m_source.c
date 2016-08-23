/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_source.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:48:51 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 18:55:41 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	my_key_func(int keycode, void *param)
{
	t_fdf	*tmp;

	tmp = (t_fdf*)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 122)
		tmp->params.eyes.y +=5;
	if (keycode == 113)
		tmp->params.eyes.x -=5;
	if (keycode == 115)
		tmp->params.eyes.y -=5;
	if (keycode == 100)
		tmp->params.eyes.x +=5;
	if (keycode == 65307)
		exit(0);
	ft_putstrnb("keycode : ", keycode);
	mlx_destroy_image(tmp->win.mlx, tmp->win.img);
	mprime(tmp);
//	mlx_clear_window(tmp->win.mlx, tmp->win.win);
	tmp->win.img = mlx_new_image(tmp->win.mlx, WIDTH, HEIGHT);
	start_draw(tmp);
	mlx_put_image_to_window(tmp->win.mlx, tmp->win.win, tmp->win.img, 50, 50);
	return (0);
}

void		put_pixel_img(void *img, int x, int y, int color)
{
	int		sizu;
	int		endian;
	int		bi;
	int		ipixel;
	char	*map;

	map = mlx_get_data_addr(img, &bi, &sizu, &endian);
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	bi /= 8;
	ipixel = x * bi + y * sizu;
	map[ipixel] = color >> 0;
	map[ipixel + 1] = color >> 8;
	map[ipixel + 2] = color >> 16;
}

void		print_map_dots(t_fdf *map)
{
	t_coord	*first_elem;
	t_coord	*cursor;

	first_elem = map->coord;
	while (first_elem)
	{
		cursor = first_elem;
		while (cursor)
		{
			put_pixel_img(map->win.img, cursor->dotp.x, cursor->dotp.y,
				get_color(map, cursor->p_val, cursor->dot.z, cursor->dot.z));
			cursor = cursor->nextx;
		}
		first_elem = first_elem->nexty;
	}
}

void		init_mlx(t_fdf *map)
{
	map->win.mlx = mlx_init();
	map->win.win = mlx_new_window(map->win.mlx, WIDTH, HEIGHT, TITLE);
	map->win.img = mlx_new_image(map->win.mlx, WIDTH, HEIGHT);
//	print_map_dots(map);
	start_draw(map);
	mlx_put_image_to_window(map->win.mlx, map->win.win, map->win.img, 50, 50);
	mlx_hook(map->win.win, 2, 1, my_key_func, map);
	mlx_loop(map->win.mlx);
}
