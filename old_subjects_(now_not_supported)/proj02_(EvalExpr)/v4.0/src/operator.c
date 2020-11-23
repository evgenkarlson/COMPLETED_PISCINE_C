/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:29:02 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:29:03 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str_utils.h"
#include "ft_list.h"
#include "operator.h"
#include "ops.h"

t_opp	g_opptab[] =
{
	{"-", &ft_sub},
	{"+", &ft_add},
	{"*", &ft_mul},
	{"/", &ft_div},
	{"%", &ft_mod}
};

void	*resolve_operator(char *str)
{
	int		i;
	void	*f;

	f = 0;
	i = 0;
	while (i < 5)
	{
		if (!ft_strcmp(g_opptab[i].literal, str))
			f = g_opptab[i].f;
		else if (!ft_strcmp(g_opptab[i].literal, "") && !f)
			f = g_opptab[i].f;
		i++;
	}
	return (f);
}

int		is_hp(char *str)
{
	if (!ft_strcmp(str, "*"))
		return (1);
	if (!ft_strcmp(str, "/"))
		return (1);
	if (!ft_strcmp(str, "%"))
		return (1);
	return (0);
}

int		eval_op(char *str, int a, int b)
{
	int ret;
	int (*op)(int, int);

	op = resolve_operator(str);
	ret = op(a, b);
	return (ret);
}

void	eval_ops(t_list *n, int hp)
{
	while (n->next)
	{
		if (!hp || is_hp(n->next->str))
		{
			n->value = eval_op(n->next->str, n->value, n->next->next->value);
			free(n->next->str);
			ft_list_delete_next(n);
			free(n->next->str);
			ft_list_delete_next(n);
		}
		else
			n = n->next->next;
	}
}
