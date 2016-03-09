/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:01:45 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/09 16:34:39 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		gnl_value;
	int		line_num;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	line = NULL;
	line_num = 0;
	if (fd == -1)
	{
		ft_putstr("Erreur d'ouverture du fichier");
		return (0);
	}
	else
	{
		while ((gnl_value = get_next_line(fd, &line)) == 1)
		{
			ft_putendl(line);
			ft_putstr("Valeur de retour de get_next_line() : ");
			ft_putnbr(gnl_value);
			ft_putchar('\n');
			line_num++;
		}
		ft_putstr("BUFF_SIZE : ");
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
