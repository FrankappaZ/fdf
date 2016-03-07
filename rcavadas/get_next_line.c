/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:07:19 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 19:01:17 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* gestion de la string extract */
int	treat_extract(char *line, char *extract)
{
	int	index;

	index = 0;
	while (extract)
	{
		if (extract[index] == '\n')
		{
			line = ft_strsub(extract, 0, index);
//			extract = ft_strsub(extract, index + 1, ft_strlen(extract) - ft_strlen(line));
			extract = ft_strsub(extract, index + 1, ft_strlen(&extract[index + 1]));
			return (0);
		}
		if (extract[index] == '\0')
			return (0);
		index++;
	}
}

int	get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*extract;

	line = NULL;
	if (BUFF_SIZE < 1)
		return (-1);
	if (extract)
		treat_extract(*line, extract);
	if (line)
	{
		ft_putstr(*line);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		extract = ft_strjoin(extract, buf);
	}
	if (ret < 0)
		return (-1);
	return (0);
}	
