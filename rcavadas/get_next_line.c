/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:07:19 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 21:57:56 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* gestion de la string extract */
int	treat_extract(char *line, char *extract)
{
	int	index;

	index = 0;
	ft_putendl("Entered treat_extract.");
	while (extract)
	{
		if (extract[index] == '\n')
		{
			line = ft_strsub(extract, 0, index);
			extract = ft_strsub(extract, index + 1, ft_strlen(extract) -
					ft_strlen(line));
			return (0);
		}
		if (extract[index] == '\0')
			return (0);
		index++;
	}
	return (0);
}

int	get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*extract;

	ft_putendl("get_next_line called");
	line = NULL;
	ft_putendl("line set to NULL");
	extract = NULL;
	ft_putendl("extract set to NULL");
	if (BUFF_SIZE < 1)
	{
		ft_putendl("error : BUFF_SIZE < 1");
		return (-1);
	}
	if (extract)
	{
		ft_putendl("There is an extract");
		treat_extract(*line, extract);
	}
	if (line)
	{
		ft_putendl("There is a line");
		return (1);
	}
	ret = read(fd, buf, BUFF_SIZE);
	ft_putnbr(ret); ft_putchar('\n');
	if (ret > 0)
	{
		ft_putendl("ret > 0");
		buf[ret] = '\0';
		extract = ft_strjoin(extract, buf);
		ft_putendl("extract and buf have been joined.");
		ft_putendl("Going to call get_next_line recursively.");
		get_next_line(fd, line);
	}
	if (ret == 0)
	{
		ft_putendl("ret == 0");
		if (extract)
			free(extract);
		return (0);
	}
	else if (ret < 0)
	{
		ft_putendl("ret < 0");
		if (extract)
			free(extract);
		return (-1);
	}
	return (0);
}
