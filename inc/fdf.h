/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:32:27 by rcavadas          #+#    #+#             */
/*   Updated: 2016/07/05 20:51:31 by abureau          ###   ########.fr       */
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

# define CCYA 0X0000FFFF
# define CRED 0X00FF0000
# define CWHI 0X00FFFFFF
# define CORA 0X00FF7500
# define CYEL 0X00FFFF00
# define CGRE 0X0000FF00
# define CBLU 0X000000FF
# define CPIN 0X00FF00FF
# define CBLA 0X00000000

# define RP0 (unsigned int)(((p_now - 0.) * 5.)* 0XFF/ 100.)
# define RP20 (unsigned int)(((p_now - 20.) * 5.)* 0XFF/ 100.)
# define RP40 (unsigned int)(((p_now - 40.) * 5.)* 0XFF/ 100.)
# define RP60 (unsigned int)(((p_now - 60.) * 5.)* 0XFF/ 100.)
# define RP80 (unsigned int)(((p_now - 80.) * 5.)* 0XFF/ 100.)

#define RANGE params.z_range.range_z
#define LOW_RANGE params.z_range.l_range_z
#define HIGH_RANGE params.z_range.h_range_z

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


typedef struct		s_range
{
	int				l_range_z;
	int				h_range_z;
	int				range_z;
}					t_range;

typedef struct		s_params
{
	struct s_range	z_range;
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
void				get_range(t_fdf *map);
int				get_color(t_fdf *map, int p_beg, int value, int next);
void				linker(t_coord *begin);
void				map_explorer(t_coord *begin);
void				mprime(t_fdf *map);
void				put_pixel_img(void *img, int x, int y, int color);

#endif
