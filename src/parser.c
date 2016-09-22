/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:12:24 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 16:34:45 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>

static t_dot	create_dot(int value, int y)
{
	t_dot dot;

	dot.z = value;
	dot.y = y;
	return (dot);
}

static t_coord	*get_values(char *line, int y, t_coord *begin)
{
	int	i;
	int	value;

	i = 0;
	line = ft_strtrim(line);
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	value = ft_atoi(ft_strsub(line, 0, i));
	begin = addlst(begin, create_dot(value, y));
	if (line[i])
		get_values(&line[i], y, begin);
	return (begin);
}

t_dot			rotate_point(t_fdf *map, t_dot dot, t_dot center)
{
	float sn;
	float cs;
	float xnew;
	float ynew;

	sn = sin(map->params.rad);
	cs = cos(map->params.rad);
	dot.x -= center.x;
	dot.y -= center.y;
	xnew = dot.x * cs - dot.y * sn;
	ynew = dot.x * sn + dot.y * cs;
	dot.x = xnew + center.x;
	dot.y = ynew + center.y;
	return(dot);
}

void			coord_rotate(t_fdf *map, t_coord *begin, t_dot center)
{
	t_coord	*first_elem;
	t_coord	*cursor;

	first_elem = begin;
	while (first_elem)
	{
		cursor = first_elem;
		while (cursor->nextx)
		{
			cursor->dot = rotate_point(map ,cursor->dot, center);
			cursor = cursor->nextx;
		}
		cursor->dot = rotate_point(map ,cursor->dot, center);
		first_elem = first_elem->nexty;
	}
}

t_coord			*parser(int fd, t_coord *begin, t_params param)
{
	char	*line;
	int		y;

	line = NULL;
	y = 0;
	while (get_next_line(fd, &line))
		begin = get_values(line, y++, begin);
	linker(begin);
	coord_setter(begin, param);
	return (begin);
}
