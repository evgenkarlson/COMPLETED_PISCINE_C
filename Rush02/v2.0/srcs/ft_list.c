/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbufnoir <rbufnoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 14:09:14 by rbufnoir          #+#    #+#             */
/*   Updated: 2014/07/20 15:06:24 by rbufnoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

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
	t_list *l;

	tmp = jp_create_elem(str);
	if (begin_list == NULL)
		*begin_list = tmp;
	else
	{
		l = *begin_list;
		while (l->next != NULL)
			l = l->next;
		l->next = tmp;
	}
}

int		jp_list_size(t_list **begin_list)
{
	int		i;
	t_list	*ptr;

	i = 1;
	if (*begin_list == NULL)
		return (0);
	ptr = *begin_list;
	while (ptr->next != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
