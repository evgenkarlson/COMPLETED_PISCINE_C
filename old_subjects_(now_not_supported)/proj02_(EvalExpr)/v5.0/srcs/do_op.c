/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:11:22 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 19:37:16 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		define_op(char oper, t_opp *g_opptab)
{
	int		op;

	op = 0;
	while (op < 5)
	{
		if (oper == g_opptab[op].operand)
			return (op);
		op++;
	}
	return (op);
}

int		do_op(int nb1, int nb2, char oper)
{
	t_opp	g_opptab[5];
	int		res;
	int		op;

	g_opptab[0].operand = '+';
	g_opptab[0].operation = ft_add;
	g_opptab[1].operand = '-';
	g_opptab[1].operation = ft_sub;
	g_opptab[2].operand = '*';
	g_opptab[2].operation = ft_mul;
	g_opptab[3].operand = '/';
	g_opptab[3].operation = ft_div;
	g_opptab[4].operand = '%';
	g_opptab[4].operation = ft_mod;
	op = define_op(oper, g_opptab);
	res = (g_opptab[op].operation)(nb1, nb2);
	return (res);
}
