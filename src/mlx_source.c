#include "../inc/fdf.h"

static void		put_pixel_img(void * img, int x, int y, int color)
{
	int		sizu;
	int		endian;
	int		bi;
	int		ipixel;
	char	*map = mlx_get_data_addr(img, &bi, &sizu, &endian);

	if (x >= HEIGHT || y >= WIDTH)
		return ;
	ipixel = x * bi + y * sizu;
	map[ipixel] = color >> 0;
	map[ipixel + 1] = color >> 8;
	map[ipixel + 2] = color >> 16;
}
