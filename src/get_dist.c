/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 20:02:42 by abureau           #+#    #+#             */
/*   Updated: 2016/08/09 20:10:08 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		get_dist(int xbeg, int ybeg, int xend, int yend)
{
	float	sqrx;
	float	sqry;
	int	sqrt;

	sqrx = (square_f(xend - xbeg));
	sqry = (square_f(yend - ybeg));
	sqrt = ft_squaroot(sqrx + sqry);
	return (sqrt);
}
