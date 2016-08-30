
#include "../inc/fdf.h"
#include "../inc/rota.h"

void		free_elem(t_coord *elem, t_fdf *map)
{
	if (map)
	{
		ft_putendl("free coord :");
		if(elem->nextx)
		{
			ft_putendl("\tfree link nextx");
			free(elem->nextx);
			elem->nextx = NULL;
		}
		if(elem->nexty)
		{
			ft_putendl("\tfree link nexty");
			free(elem->nexty);
			elem->nexty = NULL;
		}
		if(elem != NULL)
		{
			ft_putendl("\tfree elem");
			free(elem);
			elem = NULL;
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

