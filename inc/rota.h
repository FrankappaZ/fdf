/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 16:38:54 by rcavadas          #+#    #+#             */
/*   Updated: 2016/09/22 14:53:47 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTA_H
# define ROTA_H
# include "./fdf.h"

void		set_last_elem(t_coord *elem, t_fdf *map);
t_coord		*get_last_elem(t_coord *elem);
void		list_mod(t_fdf *map, void (*ptr_func)(t_coord*, t_fdf*));
void		free_elem(t_coord *elem, t_fdf *map);
void		map_printer(t_coord *elem, t_fdf *map);
void		map_printer_p(t_coord *elem, t_fdf *map);
void		set_p_value(t_coord *elem, t_fdf *map);
void		count_elem(t_coord *elem, t_fdf *map);
//void		get_range(t_coord *elem, t_fdf *map);
#endif
