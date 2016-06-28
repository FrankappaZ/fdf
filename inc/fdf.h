/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:32:27 by rcavadas          #+#    #+#             */
/*   Updated: 2016/06/28 18:48:05 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
}					t_dot;

typedef struct		s_coord
{
	struct s_dot	dot;
	struct s_coord	*nextx;
	struct s_coord	*nexty;
}					t_coord;

typedef struct		s_params
{
	int				spacing;
	int				hor_pad;
	int				ver_pad;
	int				z_multiplyer;
	float			radius;
}					t_params;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	int				win_hei;
	int				win_len;
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
void				linker(t_coord *begin);
void				map_explorer(t_coord *begin);

#endif
