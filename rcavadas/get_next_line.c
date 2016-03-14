/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:07:19 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/14 15:07:20 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	malloc_fd_array(char ***extract)
{
	int		index;
	char	**tmp_buff;

	index = 0;
	tmp_buff = NULL;
	if (!*extract)
	{
		tmp_buff = (char**)malloc(sizeof(char*) * 256);
		if (tmp_buff)
		{
			while (index < 256)
			{
				tmp_buff[index] = (char*)malloc(sizeof(char) * 1);
				if (tmp_buff[index])
					index++;
				else
					while (index-- > 0)
						ft_strdel(&tmp_buff[index]);
			}
			*extract = tmp_buff;
		}
	}
}

int		treat_extract(char **line, char **extract)
{
	int	index;

	index = 0;
	while (extract[0][index])
	{
		if (extract[0][index] == '\n')
		{
			*line = ft_strsub(*extract, 0, index);
			*extract = ft_strsub(*extract, index + 1, ft_strlen(*extract) -
					ft_strlen(*line));
			return (1);
		}
		index++;
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	**extract = NULL;

	malloc_fd_array(&extract);
	if (fd < 0 || fd > 255 || !line)
		return (-1);
	if (extract[fd] && (treat_extract(line, &extract[fd])))
		return (1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		buf[ret] = '\0';
		extract[fd] = ft_strjoin(extract[fd], buf);
	}
	if (ret == 0 && (extract[fd] && ft_strlen(extract[fd]) > 0))
	{
		*line = ft_strdup(extract[fd]);
		ft_strdel(&extract[fd]);
		return (1);
	}
	if (ret == 0)
		return (0);
	return (ret < 0 ? -1 : get_next_line(fd, line));
}
