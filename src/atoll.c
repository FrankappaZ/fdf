/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:36:17 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 15:48:25 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../inc/fdf.h"

static void		ft_initlongvar(ll64 *i, int *p, int *state)
{
	*i = 0;
	*p = 0;
	*state = 0;
}

static long long	ft_return(ll64 i, int p, int state)
{
	if (state > 1)
		return (0);
	else if (state == 1)
		if (!p)
			return (-i);
	return (i);
}

long long		ft_atoll(const char *s)
{
	long long	i;
	int		state;
	int		p;
	char	*str;

	ft_initlongvar(&i, &p, &state);
	str = ft_strdup(s);
	if (str)
	{
		while ((*str > 0x00) && (*str <= 0x20))
		{
			str++;
		}
		if (*str == '+' || *str == '-')
		{
			if (*str == '+')
				p = 1;
			state++;
			str++;
		}
		while (*str != '\0' && ft_isdigit(*str))
			i = i * 10 + *str++ - '0';
		i = ft_return(i, p, state);
	}
	return (i);
}
