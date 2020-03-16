/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:22:19 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:22:21 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "str_utils.h"
#include "utils.h"
#include "tokens.h"
#include "operator.h"
#include "eval.h"

int		eval_operand(char *str)
{
	char expr[ft_strlen(str) - 1];

	if (*str == '-' && *(str + 1) == '(')
	{
		ft_strlcpy(expr, str + 2, ft_strlen(str) - 2);
		return (-eval_expr(expr));
	}
	if (*str == '(')
	{
		ft_strlcpy(expr, str + 1, ft_strlen(str) - 1);
		return (eval_expr(expr));
	}
	else
		return (ft_atoi(str));
}

void	eval_operands(t_list *n)
{
	while (n)
	{
		n->value = eval_operand(n->str);
		n = n->next;
		if (n)
			n = n->next;
	}
}

int		eval_expr(char *str)
{
	t_list	*n;
	char	*token;
	int		ret;
	int		even;

	n = 0;
	even = 0;
	while (*str)
	{
		token = get_token(&str, &even);
		if (token)
			ft_list_push_back(&n, token);
		else
			break ;
	}
	eval_operands(n);
	eval_ops(n, 1);
	eval_ops(n, 0);
	ret = n->value;
	free(n->str);
	free(n);
	return (ret);
}
