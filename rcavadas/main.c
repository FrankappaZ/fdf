/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:01:45 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/09 18:00:59 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int 	fd2;
	char	*line;
	int		gnl_value;
	int		line_num;

	if (argc == 1)
		fd1 = 0;
	else
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
	}
	line = NULL;
	line_num = 0;
	if (fd1 == -1)
	{
		ft_putstr("Erreur d'ouverture du fichier");
		return (0);
	}
	else
	{
//		Test sur un seul fd
//		while ((gnl_value = get_next_line(fd1, &line)) == 1)
//		{
//			ft_putendl(line);
//			line_num++;
//		}
//		ft_putstr("\nNumero de la derniere line affichee : ");
//		ft_putnbr(line_num - 1);

//		Test sur deux fd
		get_next_line(fd1, &line);
		ft_putendl(line);
		ft_putnbr((gnl_value = get_next_line(fd1, &line)));
		ft_putendl("\n\n");
		get_next_line(fd2, &line);
		ft_putendl(line);
		ft_putnbr((gnl_value = get_next_line(fd2, &line)));
		ft_putendl("\n\n");
	}

	/* Implementer un test de nouvel appel de get_next_line()
	apres avoir atteint EOF */

	ft_putstr("\nValeur de retour de get_next_line() : ");
	ft_putnbr(gnl_value);
	close(argv[1]);
	close(argv[2]);
	return (0);
}
