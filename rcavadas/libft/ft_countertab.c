/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countertab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:38:50 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 17:57:34 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_counter	*ft_countertab(const char *str)
{
	int			i;
	t_counter	*tab;
	int			nb;

	i = ft_atoi(str);
	tab = (t_counter*)malloc(sizeof(t_counter) * i);
	nb = i;
	while (i)
	{
		i--;
		tab[i] = ft_counterinit(nb, i);
	}
	return (tab);
}
