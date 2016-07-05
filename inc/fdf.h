/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:32:27 by rcavadas          #+#    #+#             */
/*   Updated: 2016/07/05 17:20:20 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# define HEIGHT 1000
# define WIDTH 1600
# define SPACING 50
# define RAD M_PI/4.
# define TITLE "Window title"

typedef struct		s_dot
{
	float				x;
	float				y;
	float				z;
}					t_dot;

typedef struct		s_dotp
{
	float				x;
	float				y;
}					t_dotp;

typedef struct		s_coord
{
	struct s_dot	dot;
	struct s_dotp	dotp;
	struct s_dot	eyes;
	struct s_coord	*nextx;
	struct s_coord	*nexty;
}					t_coord;

typedef struct		s_params
{
	int				spacing;
	int				hor_pad;
	int				ver_pad;
	int				z_mod;
	int				eyes_z;
	float			rad;
}					t_params;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_win;

typedef struct		s_fdf
{
	struct s_win	win;
	struct s_coord	*coord;
	struct s_params	params;
}					t_fdf;

t_coord				*addlst(t_coord *begin, t_dot dot);
t_coord				*parser(int fd, t_coord *begin);
void				coord_setter(t_coord *begin);
void				init_mlx(t_fdf *map);
void				linker(t_coord *begin);
void				map_explorer(t_coord *begin);
void				mprime(t_fdf *map);
void				put_pixel_img(void *img, int x, int y, int color);
void				set_proj_coord(t_coord *coord, t_fdf *map);

#endif
