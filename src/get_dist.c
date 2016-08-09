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
	return (ft_squaroot((ft_square(xend - xbeg)) + (ft_squaroot(yend, ybeg))));
}
