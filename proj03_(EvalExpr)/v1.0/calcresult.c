/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcresult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 22:43:48 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/23 22:46:11 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		do_operation(int x, int y, char op)
{
	if (op == '+')
		return (x + y);
	if (op == '-')
		return (x - y);
	if (op == '*')
		return (x * y);
	if (op == '/')
		return (x / y);
	else
		return (x % y);
}

int		calc_result(char **arr)
{
	int i;
	int x;
	int y;

	i = 0;
	while (arr[i][0] != 'e')
	{
		if (is_number(arr[i][0]))
			rpush(ft_atoi(arr[i]));
		if (is_operator(arr[i][0]))
		{
			x = rpop();
			y = rpop();
			rpush(do_operation(y, x, arr[i][0]));
		}
		i++;
	}
	return (g_rstack.stk[0]);
}
