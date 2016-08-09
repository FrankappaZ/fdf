/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <uid@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 20:06:27 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/09 20:06:28 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	bres_case_0(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if (math->dx >= math->dy)
	{
		delta_case_0(math);
		while ((math->x0 = math->x0 + 1) != math->x1)
		{
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
			if ((math->e = math->e - math->dy) < 0)
			{
				math->y0 = math->y0 + 1;
				math->e = math->e + math->dx;
			}
		}
	}
	else
	{
		delta_case_1(math);
		while ((math->y0 = math->y0 + 1) != math->y1)
		{
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
			if ((math->e = math->e - math->dx) < 0)
			{
				math->x0 = math->x0 + 1;
				math->e = math->e + math->dy;
			}
		}
	}
}

void	bres_case_1(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if (math->dx >= -(math->dy))
	{
		delta_case_0(math);
		while ((math->x0 = math->x0 + 1) != math->x1)
		{
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
			if ((math->e = math->e - math->dy) < 0)
			{
				math->y0 = math->y0 - 1;
				math->e = math->e + math->dx;
			}
		}
	}
	else
	{
		delta_case_1(math);
		while ((math->y0 = math->y0 + 1) == math->y1)
		{
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
			if ((math->e = math->e + math->dx) > 0)
			{
				math->x0 = math->x0 + 1;
				math->e = math->e + math->dy;
			}
		}
	}
}

void	bres_case_2(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if (-(math->dx) >= math->dy)
	{
		delta_case_0(math);
		while ((math->x0 = math->x0 - 1) != math->x1)
		{
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
			if ((math->e = math->e + math->dx) >= 0)
			{
				math->y0 = math->y0 + 1;
				math->e = math->e + math->dx;
			}
		}
	}
	else
	{
		delta_case_1(math);
		while ((math->y0 = math->y0 + 1) != math->y1)
		{
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
			if ((math->e = math->e + math->dx) >= 0)
			{
				math->y0 = math->y0 + 1;
				math->e = math->e + math->dx;
			}
		}
	}
}

void	bres_case_3(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if (math->dx <= math->dy)
	{
		delta_case_0(math);
		while ((math->x0 = math->x0 - 1) != math->x1)
		{
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
			if ((math->e = math->e - math->dy) >= 0)
			{
				math->y0 = math->y0 + -1;
				math->e = math->e + math->dx;
			}
		}
	}
	else
	{
		delta_case_1(math);
		while ((math->y0 = math->y0 - 1) != math->y1)
		{
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
			if ((math->e = math->e - math->dx) >= 0)
			{
				math->x0 = math->x0 - 1;
				math->e = math->e + math->dx;
			}
		}
	}
}

void	bres_case_4(t_math *math, t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	if ((math->dy = math->y1 - math->y0) != 0)
	{
		if (math->dy > 0)
			while ((math->y0 = math->y0 + 1) != math->y1)
				ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
	}
	else
	{
		while ((math->y0 = math->y0 - 1) != math->y1)
			ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
	}
}
