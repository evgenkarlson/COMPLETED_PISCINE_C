/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 09:11:37 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/22 09:11:41 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

#define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')
#define ONEXT(o) ((int)++*(o) & 0)
#define ENEXT(s, o, p) (ONEXT(o) + eval(s, o, p))

int		ft_iatoi(char *s, long *i)
{
	int		val;

	val = 0;
	while (IS_DIGIT(s[*i]))
		val = val * 10 + s[(*i)++] - '0';
	return (val);
}

int		eval(char *s, long *o, t_priority p)
{
	int		a;
	char	c;

	a = p <= UNARY ? 0 : eval(s, o, p - 1);
	while (42)
		if ((c = s[*o]) == ' ')
			ONEXT(o);
		else if (p == PRIMARY && c == '(')
			return (ONEXT(o) + eval(s, o, ADDITIVE) + ONEXT(o));
		else if (p == PRIMARY)
			return (ft_iatoi(s, o));
		else if (p == UNARY && (c == OP_SUB || c == OP_ADD))
			return (c == OP_SUB ? -ENEXT(s, o, p - 1) : +ENEXT(s, o, p - 1));
		else if (p == UNARY)
			return (eval(s, o, PRIMARY));
		else if (p == MULTIPLICATIVE && c == OP_MUL)
			a *= ENEXT(s, o, p - 1);
		else if (p == MULTIPLICATIVE && (c == OP_DIV || c == OP_MOD))
			c == OP_DIV ? (a /= ENEXT(s, o, p - 1)) : (a %= ENEXT(s, o, p - 1));
		else if (p == ADDITIVE && (c == OP_ADD || c == OP_SUB))
			c == OP_ADD ? (a += ENEXT(s, o, p - 1)) : (a -= ENEXT(s, o, p - 1));
		else
			return (a);
}

int		eval_expr(char *str)
{
	long	offset;

	offset = 0;
	return (eval(str, &offset, ADDITIVE));
}
