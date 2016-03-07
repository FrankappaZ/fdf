/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counterpow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:38:28 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 17:57:15 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_counter	ft_counterpow(t_counter cnt, int val, char c)
{
	cnt.value = ft_pow(cnt.value, val);
	cnt.ope = c;
	cnt.nbo = cnt.nbo + 1;
	cnt.num = cnt.num;
	return (cnt);
}
