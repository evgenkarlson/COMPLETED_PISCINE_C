/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 12:38:37 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/22 18:27:03 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*jp_create_elem(char *str)
{
	t_list *tmp;

	if ((tmp = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	jp_strcpy(tmp->str, str);
	tmp->next = NULL;
	return (tmp);
}

void	jp_list_push_back(t_list **begin_list, char *str)
{
	t_list *tmp;
	t_list *elem;

	elem = jp_create_elem(str);
	if (begin_list == NULL)
		*begin_list = elem;
	else
	{
		tmp = *begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = tmp;
	}
}
