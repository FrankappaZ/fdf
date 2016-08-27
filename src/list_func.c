
#include "../inc/fdf.h"
#include "../inc/rota.h"

void		free_elem(t_coord *elem, t_fdf *map)
{
	if (map)
	{
		ft_putendl("free coord :");
		if(elem->nextx)
		{
			ft_putendl("\tfree coord nextx");
			free(elem->nextx);
		}
		if(elem->nexty)
		{
			ft_putendl("\tfree link nexty");
			free(elem->nexty);
		}
		if(elem)
		{
			ft_putendl("\tfree elem");
			free(elem);
		}
	}
}

void		count_elem(t_coord *elem, t_fdf *map)
{
	if (elem)
		map->params.z_range.nb_elem++;
	else
		ft_putendl("elem error in list_func.c:count_elem");

}

