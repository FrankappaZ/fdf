/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_source.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:48:51 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/30 15:09:55 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"

static int	keys(int keycode, t_fdf *tmp)
{
	if (keycode == 53)
		free_data_list();
	if (keycode == 116)
		tmp->params.eyes.z += STEP;
	if (keycode == 121)
		tmp->params.eyes.z -= STEP;
	if (keycode == 126)
		tmp->params.eyes.y += STEP;
	if (keycode == 124)
		tmp->params.eyes.x -= STEP;
	if (keycode == 125)
		tmp->params.eyes.y -= STEP;
	if (keycode == 123)
		tmp->params.eyes.x += STEP;
	if (keycode == 65307)
		free_data_list();
	if (keycode == 65363)
		list_mod(tmp, &map_rotation);
	return (keycode);
}

static int	my_key_func(int keycode, void *param)
{
	t_fdf	*tmp;

	tmp = (t_fdf*)param;
	keys(keycode, tmp);
	ft_putstrnb("keycode : ", keycode);
	mprime(tmp);
	mlx_destroy_image(tmp->win.mlx, tmp->win.img);
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
	start_draw(map);
	mlx_put_image_to_window(map->win.mlx, map->win.win, map->win.img, 50, 50);
	mlx_hook(map->win.win, 2, 1, my_key_func, map);
	mlx_loop(map->win.mlx);
}
