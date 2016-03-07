/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counteradd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:36:54 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 17:55:26 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_counter	ft_counteradd(t_counter cnt, int val, char c)
{
	if (c == '+')
	{
		cnt.value = cnt.value + val;
	}
	else
	{
		cnt.value = cnt.value - val;
	}
	cnt.ope = c;
	cnt.nbo = cnt.nbo + 1;
	cnt.num = cnt.num;
	return (cnt);
}
