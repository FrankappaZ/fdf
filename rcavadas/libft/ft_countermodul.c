/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countermodul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:38:10 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 17:57:02 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_counter	ft_countermodul(t_counter cnt, int val, char c)
{
	cnt.value = cnt.value % val;
	cnt.ope = c;
	cnt.nbo = cnt.nbo + 1;
	cnt.num = cnt.num;
	return (cnt);
}
