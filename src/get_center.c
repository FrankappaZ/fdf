/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 14:53:19 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/30 16:09:24 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"

t_dot	get_center(t_fdf *map)
{
	t_dot		center;

	center.x = (map->coord->dot.x + get_last_elem(map->coord)->dot.x) / 2;
	center.y = (map->coord->dot.y + get_last_elem(map->coord)->dot.y) / 2;
	return (center);
}

t_dot	get_centerp(t_fdf *map)
{
	t_dot		center;

	center.x = (map->coord->dotp.x + get_last_elem(map->coord)->dotp.x) / 2;
	center.y = (map->coord->dotp.y + get_last_elem(map->coord)->dotp.y) / 2;
	return (center);
}
