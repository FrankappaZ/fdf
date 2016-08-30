/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 14:53:19 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/30 14:53:22 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rota.h"

t_dot	get_center(t_fdf *map)
{
	t_dot		center;

	center.x = (map->coord->dotp.x + get_last_elem(NULL)->dotp.x) / 2;
	center.y = (map->coord->dotp.y + get_last_elem(NULL)->dotp.y) / 2;
	return (center);
}
