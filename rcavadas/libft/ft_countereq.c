/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countereq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:37:30 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 17:56:03 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_counter	ft_countereq(t_counter cnt1, t_counter cnt2, char c)
{
	cnt1.value = cnt2.value;
	cnt1.ope = c;
	cnt1.nbo = cnt1.nbo + 1;
	cnt1.num = cnt1.num;
	return (cnt1);
}
