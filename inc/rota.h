/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 16:38:54 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 16:39:03 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTA_H
# define ROTA_H
# include "./fdf.h"

void		list_mod(t_fdf *map, void (*ptr_func)(t_coord*, t_fdf*));
void		map_printer(t_coord *elem, t_fdf *map);
void		map_printer_p(t_coord *elem, t_fdf *map);
void		map_rotation(t_coord *elem, t_fdf *map);
void		set_p_value(t_coord *elem, t_fdf *map);
void		count_elem(t_coord *elem, t_fdf *map);
void		get_range(t_coord *elem, t_fdf *map);
#endif
