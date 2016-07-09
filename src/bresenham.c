
# include "../inc/fdf.h"

static void	init_math(t_math *math, t_coord *dot0, t_coord *dot1)
{
	
	math->x0 = dot0->dotp.x;
	math->y0 = dot0->dotp.y;
	math->x1 = dot1->dotp.x;
	math->y1 = dot1->dotp.y;
	math->e = 0;
}

static void	octant_check()
{
	
}

static void	draw_segment(t_fdf *map, t_coord *dot0, t_coord *dot1)
{
	t_math	math;

	init_math(&math, dot0, dot1);
	if ((math.dx = math.x0 - math.x1) != 0 )
	{
		if (math.dx > 0)
		{
			if ((math.dy = math.y1 - math.y0) != 0)
			{
				if (math.dy > 0)
				{
					if (math.dx >= math.dy)
					{
						math.e = math.dx;
						math.dx = math.e * 2;
						math.dy *= 2;
						while ((math.x0 = math.x0 + 1) != math.x1)
						{
							ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
							if ((math.e = math.e - math.dy) < 0)
							{
								math.y0 = math.y0 + 1;
								math.e = math.e + math.dx;
							}
						}
					}
					else
					{
						math.e = math.dy;
						math.dy = math.e * 2;
						math.dx *= 2;
						while ((math.y0 = math.y0 + 1) != math.y1)
						{
							ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
							if ((math.e = math.e - math.dx) < 0)
							{
								math.x0 = math.x0 + 1;
								math.e = math.e + math.dy;
							}
						}
					}
				}
				else	//		dy < 0 (dx > 0)
				{
				
				}
			}
			else	//	dy = 0
			{
				while ((math.x0 = math.x0 + 1) == math.x1)
					ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
			}
		}
		else	//	dx < 0
		{
			
		}
	}
	else		//dx == 0
	{
		if ((math.dy = math.y1 - math.y0) != 0)
			if (math.dy > 0)
				while ((math.y0 = math.y0 + 1) != math.y1)
					ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
		else
				while ((math.y0 = math.y0 - 1) != math.y1)
					ft_putstr("tracePixel(x0, y0);		PRINT PIXEL HERE ;");
	}
}

void	start_draw(t_fdf *map)
{
	t_coord	*tmp;
	t_coord	*cursory;

	cursory = map->coord;
	while (cursory != NULL)
	{
		tmp = cursory;
		cursory = cursory->nexty;
		while (tmp != NULL)
		{
			if (tmp->nextx)
				draw_segment(map, tmp, tmp->nextx);
			if (tmp->nexty)
				draw_segment(map, tmp, tmp->nexty);
		tmp = tmp->nextx;
		}
	}
}
