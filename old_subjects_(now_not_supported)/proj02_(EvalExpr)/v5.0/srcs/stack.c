/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:34:58 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 22:00:28 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		find_size(char **stack)
{
	int		size;

	size = 0;
	while (stack[size])
		size++;
	return (size);
}

char	*t_s(char **stack)
{
	int		i;
	char	*cpy;

	i = 0;
	while (stack[i + 1])
		i++;
	cpy = ft_strdup(stack[i]);
	return (cpy);
}

char	*de_stack(char ***stack)
{
	int		i;
	char	*cpy;

	i = 0;
	while ((*stack)[i + 1])
		i++;
	cpy = ft_strdup((*stack)[i]);
	(*stack)[i] = NULL;
	return (cpy);
}

void	add_stack(char ***stack, char *elem)
{
	int		i;

	i = 0;
	while ((*stack)[i])
		i++;
	(*stack)[i] = ft_strdup(elem);
}
