/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counterset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:38:43 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 15:49:17 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_counter	ft_counterset(t_counter cnt, int val, char c)
{
	cnt.value = val;
	cnt.ope = c;
	cnt.nbo = cnt.nbo + 1;
	cnt.num = cnt.num;
	return (cnt);
}
