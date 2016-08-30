
#include "../inc/fdf.h"
#include "../inc/rota.h"

void		free_elem(t_coord *elem, t_fdf *map)
{
	if (map)
	{
			ft_putendl("free(elem)");
			free(elem);
			elem = NULL;
	}
}

void		count_elem(t_coord *elem, t_fdf *map)
{
	if (elem)
		map->params.z_range.nb_elem++;
	else
		ft_putendl("elem error in list_func.c:count_elem");

}

