#include "../inc/fdf.h"
#include <math.h>

void		map_rotation(t_coord *elem, t_fdf *map)
{
	t_dotp	tmp_dot;

	tmp_dot = elem->dotp;
	elem->dotp.x = (tmp_dot.x * cos(map->params.rad))
		- (tmp_dot.y * sin(map->params.rad));
	elem->dotp.y = (tmp_dot.y * cos(map->params.rad))
		+ (tmp_dot.x * sin(map->params.rad));
}

void		map_printer_p(t_coord *elem, t_fdf *map)
{
	ft_putstr("x : ");
	ft_putnbr(elem->dotp.x);
	ft_putstr(" | y : ");
	ft_putnbrnl(elem->dotp.y);
}

void		map_printer(t_coord *elem, t_fdf *map)
{
	static int	cnt = 0;

	ft_putnbr(cnt);
	ft_putstr(" :: ");
	ft_putstr("x : ");
	ft_putnbr(elem->dot.x);
	ft_putstr(" | y : ");
	ft_putnbr(elem->dot.y);
	ft_putstr(" | z : ");
	ft_putnbrnl(elem->dot.z);
	cnt++;
}

void		list_mod(t_fdf *map, void (*ptr_func)(t_coord*, t_fdf*))
{
	t_coord	*first_elem;
	t_coord	*cursor;

	first_elem = map->coord;
	while (first_elem)
	{
		cursor = first_elem;
		while (cursor)
		{
			ptr_func(cursor, map);
			cursor = cursor->nextx;
		}
		first_elem = first_elem->nexty;
	}
}
