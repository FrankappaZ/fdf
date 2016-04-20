/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:45:20 by rcavadas          #+#    #+#             */
/*   Updated: 2016/03/07 15:50:32 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*nextl;

	if (alst && del && *alst)
	{
		tmp = *alst;
		while (tmp)
		{
			nextl = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = nextl;
		}
		*alst = NULL;
	}
}
