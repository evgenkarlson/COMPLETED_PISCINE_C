/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polish2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 22:02:15 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 22:03:08 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		is_operator(char *elem)
{
	return (ft_strlen(elem) == 1
			&& (*elem == '+' || *elem == '-' || *elem == '*' || *elem == '/'
				|| *elem == '%' || *elem == '(' || *elem == ')'));
}

int		f_prio(char *elem)
{
	if (elem == NULL)
		return (-1);
	else if (ft_strcmp(elem, "*") == 0 || ft_strcmp(elem, "/") == 0
			|| ft_strcmp(elem, "%") == 0)
		return (2);
	else if (ft_strcmp(elem, "+") == 0 || ft_strcmp(elem, "-") == 0)
		return (1);
	else if (ft_strcmp(elem, "(") == 0)
		return (0);
	return (-1);
}
