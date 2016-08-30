/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:32:27 by rcavadas          #+#    #+#             */
/*   Updated: 2016/08/30 12:39:16 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
#include <mlx.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# define HEIGHT 500
# define WIDTH 800
# define SPACING 50
# define RAD M_PI/4.
# define TITLE "FDF_42"

/*	ROOT_P = precision de la racine, change le nb de loop dans le cacul de la couleur accelere potenciellment le programme (default 10) */
# define ROOT_P 2

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

# define RANGE params.z_range.range_z
# define LOW_RANGE params.z_range.l_range_z
# define HIGH_RANGE params.z_range.h_range_z

# define X1 dotp.x
# define Y1 dotp.y
# define X2 nextx->dotp.x
# define Y2 nextx->dotp.y
# define X3 nexty->dotp.x
# define Y3 nexty->dotp.y


typedef struct			s_math
{
	int					color;
	int					dx;
	int					dy;
	int					dp;
	float				dist;
	int					e;
	int					deltaE;
	int					deltaNE;
	int					x0;
	int					y0;
	int					x1;
	int					y1;
}						t_math;

typedef struct			s_dot
{
	float				x;
	float				y;
	int					z;
}						t_dot;

typedef struct			s_dotp
{
	float				x;
	float				y;
}						t_dotp;

typedef struct			s_coord
{
	struct s_dot		dot;
	struct s_dotp		dotp;
	struct s_coord		*nextx;
	struct s_coord		*nexty;
	int					p_val;
}						t_coord;


typedef struct			s_range
{
	int					l_range_z;
	int					h_range_z;
	int					range_z;
	int					nb_elem;
}
						t_range;

typedef struct			s_params
{
	struct s_range		z_range;
	int					color_tab;
	int					spacing;
	int					hor_pad;
	int					ver_pad;
	int					z_mod;
	float				rad;
	struct s_dot		eyes;
}						t_params;

typedef struct			s_win
{
	void				*mlx;
	void				*win;
	void				*img;
}						t_win;

typedef struct			s_fdf
{
	struct s_win		win;
	struct s_coord		*coord;
	struct s_params		params;
}						t_fdf;

typedef unsigned long	u64;
typedef long			ll64;

char					*ft_lltoabase(u64 nbr, unsigned int base, int signe);
float					square_f(float val);
int						ft_squaroot(float nbr);
int						get_color(t_fdf *map, float p_beg, float prev,
	float next);
int						get_dist(int xbeg, int ybeg, int xend, int yend);
long long				ft_atoll(const char *s);
t_coord					*addlst(t_coord *begin, t_dot dot);
t_coord					*parser(int fd, t_coord *begin);
u64						get_data_add(u64 ptr);
void					bres_case_0(t_math *math, t_fdf *map, t_coord *dot0,
	t_coord *dot1);
void					bres_case_1(t_math *math, t_fdf *map, t_coord *dot0,
	t_coord *dot1);
void					bres_case_2(t_math *math, t_fdf *map, t_coord *dot0,
	t_coord *dot1);
void					bres_case_3(t_math *math, t_fdf *map, t_coord *dot0,
	t_coord *dot1);
void					bres_case_4(t_math *math, t_fdf *map, t_coord *dot0,
	t_coord *dot1);
void					coord_setter(t_coord *begin);
void					delta_case_0(t_math *math);
void					delta_case_1(t_math *math);
void					draw_segment(t_fdf *map, t_coord *dot0, t_coord *dot1);
void					dx_inf_dy(t_math *math, t_fdf *map, t_coord *dot0,
	t_coord *dot1);
void					dx_sup_dy(t_math *math, t_fdf *map, t_coord *dot0,
	t_coord *dot1);
void					dx_sup_mdy(t_math *math, t_fdf *map, t_coord *dot0,
	t_coord *dot1);
void					free_data_list();
void					get_range(t_fdf *map);
void					init_mlx(t_fdf *map);
void					linker(t_coord *begin);
void					map_explorer(t_coord *begin);
void					mdx_sup_dy(t_math *math, t_fdf *map, t_coord *dot0,
	t_coord *dot1);
void					mprime(t_fdf *map);
void					put_pixel_img(void *img, int x, int y, int color);
void					setup_catch();
void					start_draw(t_fdf *map);
#endif
