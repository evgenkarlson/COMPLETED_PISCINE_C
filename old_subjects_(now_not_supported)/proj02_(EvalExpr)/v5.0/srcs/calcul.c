/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 19:34:15 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 20:41:40 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		calc_polish(char **polish)
{
	int		size;
	int		*stack;
	int		i;
	int		k;

	size = find_size(polish);
	if (!(stack = (int*)malloc(sizeof(int) * (size + 1))))
		return (0);
	k = 0;
	while (k < size)
		stack[k++] = 0;
	k = 0;
	i = 0;
	while (polish[i])
	{
		if (!is_operator(polish[i]))
			stack[k++] = ft_atoi(polish[i++]);
		else
		{
			stack[k - 2] = do_op(stack[k - 2], stack[k - 1], *(polish[i]));
			k--;
			i++;
		}
	}
	return (stack[0]);
}
