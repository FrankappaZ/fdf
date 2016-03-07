/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counterinit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:37:46 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 17:56:29 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_counter		ft_counterinit(int nb, int i)
{
	t_counter	cnt;
	t_functable	funclist;

	if (i == 0)
	{
		funclist = ft_counterinitfunc();
		cnt.func = funclist;
	}
	cnt.value = 0;
	cnt.ope = 'i';
	cnt.nbo = 0;
	cnt.num = nb;
	return (cnt);
}
