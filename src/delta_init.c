/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 19:40:51 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 20:01:52 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	delta_case_0(t_math *math)
{
	math->e = math->dx;
	math->dx = math->e * 2;
	math->dy *= 2;
}

void	delta_case_1(t_math *math)
{
	math->e = math->dy;
	math->dy = math->e * 2;
	math->dx *= 2;
}
