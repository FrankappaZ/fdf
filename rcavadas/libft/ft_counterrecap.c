/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counterrecap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:38:36 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 17:57:20 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_counterrecap(t_counter *cnt)
{
	int i;

	i = 0;
	ft_putstrnb("NUMBER OF VAR : ", cnt[0].num);
	while (i < cnt[0].num)
	{
		ft_putchar('\n');
		ft_putstrnb("Check var numero : ", i);
		ft_putstrnb("Check value      : ", cnt[i].value);
		ft_putstr("Check last ope   : ");
		ft_putchar(cnt[i].ope);
		ft_putchar('\n');
		ft_putstrnb("Check number of ope : ", cnt[i].nbo);
		i++;
	}
}
