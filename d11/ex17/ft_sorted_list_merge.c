/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 03:18:47 by jaleman           #+#    #+#             */
/*   Updated: 2016/11/26 03:18:47 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, \
								int (*cmp)())
{
	t_list	*tail;
	t_list	*head1;
	t_list	*head2;
	int		compare;

	if (!*begin_list1 || !begin_list2)
	{
		*begin_list1 = begin_list2 ? begin_list2 : *begin_list1;
		return ;
	}
	compare = (*cmp)(begin_list2->data, (*begin_list1)->data);
	head1 = (compare < 0) ? *begin_list1 : (*begin_list1)->next;
	head2 = (compare < 0) ? begin_list2->next : begin_list2;
	*begin_list1 = (compare < 0) ? begin_list2 : begin_list1;
	tail = *begin_list1;
	while (head1 && head2)
	{
		compare = (*cmp)(head2->data, head1->data);
		tail->next = (compare < 0 ? head2 : head1);
		head1 = compare < 0 ? head1 : head1->next;
		head2 = compare < 0 ? head2->next : head2;
		tail = tail->next;
	}
	tail->next = head2 ? head2 : head1;
}
