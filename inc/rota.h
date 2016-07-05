#ifndef ROTA_H
# define ROTA_H
# include "./fdf.h"

void		map_rotation(t_coord *elem, t_fdf *map);
void		map_printer(t_coord *elem, t_fdf *map);
void		map_printer_p(t_coord *elem, t_fdf *map);
void		list_mod(t_fdf *map, void (*ptr_func)(t_coord*, t_fdf*));


#endif
