
#include "../inc/fdf.h"
#include "../inc/rota.h"

void		free_elem(t_coord *elem, t_fdf *map)
{
	free(elem->nextx);
	free(elem->nexty);
	free(elem);
	elem = NULL;

}

void		count_elem(t_coord *elem, t_fdf *map)
{
	if (elem)
		map->params.z_range.nb_elem++;
	else
		ft_putendl("elem error in list_func.c:count_elem");

}

/*
void	get_range(t_coord *elem, t_fdf *map)
{
	if (elem)
	{
		if (elem->dot.z < LOW_RANGE)
			LOW_RANGE = elem->dot_z;
		else if (elem->dot.z > MAX_RANGE)
			MAX_RANGE = elem->dot_z;
		RANGE = MAX_RANGE - LOWRANGE;
	}
	else
		ft_putendl("elem error in list_func.c:get_range");
}
*/
