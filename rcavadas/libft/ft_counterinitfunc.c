/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counterinitfunc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:37:54 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 17:56:42 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_functable		ft_counterinitfunc(void)
{
	t_functable func;

	func.carac = ft_strdup("+-/*s%p");
	func.functab[0] = ft_counteradd;
	func.functab[1] = ft_counteradd;
	func.functab[2] = ft_counterdiv;
	func.functab[3] = ft_countermul;
	func.functab[4] = ft_counterset;
	func.functab[5] = ft_countermodul;
	func.functab[6] = ft_counterpow;
	return (func);
}
