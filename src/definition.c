#include "../inc/fdf.h"

static t_coord	*creat_coord(t_dot dot)
{
	t_coord	*elem;

	elem = (t_coord*)ft_memalloc(sizeof(t_coord));
	ft_bzero(elem, sizeof(t_coord));
	elem->dot = dot;
	return(elem);
}

static t_dot	defdot(int x, int y, int z)
{
	t_dot	new_dot;

	new_dot.x = x;
	new_dot.y = y;
	new_dot.z = z;
	return (new_dot);
}

void	draw_def(t_fdf *map)
{
	t_coord *def;

	def = NULL;
	if (map)
		def = map->defcoord;
}

t_coord		*init_def_coord(t_fdf *map)
{
	t_coord *begdef;

	begdef = creat_coord(defdot(0,0,map->LOW_RANGE));
	begdef = addlst(begdef, defdot(WIDTHD, 0, map->LOW_RANGE));
	begdef = addlst(begdef, defdot(0, HEIGHTD, map->HIGH_RANGE));
	begdef = addlst(begdef, defdot(WIDTHD, HEIGHTD, map->HIGH_RANGE));
	return (begdef);
}
