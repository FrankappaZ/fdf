#include "../inc/fdf.h"
#include "../inc/rota.h"

t_dot	get_center(t_fdf *map)
{
	t_dot		center;

	center.x = (map->coord->dotp.x + get_last_elem(NULL)->dotp.x) / 2;
	center.y = (map->coord->dotp.y + get_last_elem(NULL)->dotp.y) / 2;
	return (center);
}
