/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 03:09:49 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/26 03:09:50 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*link;
	t_list	*new_link;

	link = *begin_list;
	new_link = ft_create_elem(data);
	if (!link || (*cmp)(data, link->data) < 0)
	{
		*begin_list = new_link;
		new_link->next = link ? link : NULL;
		return ;
	}
	while (link->next)
	{
		if ((*cmp)(data, link->data) > 0 && (*cmp)(data, link->next->data) <= 0)
		{
			new_link->next = link->next;
			link->next = new_link;
			return ;
		}
		link = link->next;
	}
	link->next = new_link;
}
