/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:12:24 by rcavadas          #+#    #+#             */
/*   Updated: 2016/06/28 18:29:53 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

t_coord			*parser(int fd, t_coord *begin)
{
	char	*line;
	int		y;

	line = NULL;
	y = 0;
	while (get_next_line(fd, &line))
		begin = get_values(line, y++, begin);
	linker(begin);
	coord_setter(begin);
	return (begin);
}
