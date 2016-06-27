/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:12:24 by rcavadas          #+#    #+#             */
/*   Updated: 2016/06/27 19:39:16 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	get_values(char *line, int y, t_coord *begin)
{
	int	i;
	int	value;

	i = 0;
	line = ft_strtrim(line);
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	value = ft_atoi(ft_strsub(line, 0, i));
	ft_putnbr(value);
	ft_putchar(' ');
	if (line[i])
		get_values(&line[i], y, begin);
}

t_coord	*parser(int fd)
{
	char	*line;
	int		y;
	t_coord	*begin;

	line = NULL;
	y = 0;
	begin = NULL;
	while (get_next_line(fd, &line))
	{
		get_values(line, y++, begin);
		ft_putchar('\n');
	}
	return (begin);
}
