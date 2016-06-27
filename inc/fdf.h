/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:32:27 by rcavadas          #+#    #+#             */
/*   Updated: 2016/06/27 19:21:39 by rcavadas         ###   ########.fr       */
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

typedef struct		s_fdf
{
	struct s_coord	*coord;
	void			*mlx;
	void			*win;
}					t_fdf;

t_coord				*addlst(t_coord *begin, t_dot dot);
t_coord				*parser(int fd);

#endif
