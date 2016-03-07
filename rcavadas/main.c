/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:01:45 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/19 16:06:58 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = open("text_sample", O_RDONLY)) == -1)
	{
		ft_putstr("Erreur d'ouverture du fichier");
		return (0);
	}
	else
		get_next_line(fd, &line);
	return (0);
}