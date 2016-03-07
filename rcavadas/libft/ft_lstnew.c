/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:45:50 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/10 18:05:56 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(*tmp));
	if (!tmp)
		return (NULL);
	if (!content)
	{
		tmp->content = (void*)NULL;
		tmp->content_size = (size_t)0;
	}
	else
	{
		tmp->content = (void*)malloc(content_size);
		if (!tmp->content)
			return (NULL);
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
