/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:01:45 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/08 14:47:12 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		gnl_value;
	int		line_num;

	line = NULL;
	line_num = 0;
	if ((fd = open("text_sample", O_RDONLY)) == -1)
	{
		ft_putstr("Erreur d'ouverture du fichier");
		return (0);
	}
	else
	{
		while ((gnl_value = get_next_line(fd, &line)) == 1)
		{
			ft_putendl(line);
			line_num++;
		}
		ft_putstr("\nBUFF_SIZE : ");
		ft_putnbr(BUFF_SIZE);
		ft_putstr("\nNumero de la derniere line affichee : ");
		ft_putnbr(line_num - 1);
	}

	/* Tester un nouvel appel de get_next_line() apres avoir atteint EOF */
//	get_next_line(fd, &line);
//	ft_putendl(line);

	ft_putstr("\nValeur de retour de get_next_line() : ");
	ft_putnbr(gnl_value);
	return (0);
}
