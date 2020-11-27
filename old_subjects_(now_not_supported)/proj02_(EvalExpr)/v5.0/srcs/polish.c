/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:03:22 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 22:04:05 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

void	destack_prio(char ***polish, char ***stack, int *k)
{
	if (!(ft_strcmp(t_s(*stack), "(") == 0
				|| ft_strcmp(t_s(*stack), ")") == 0))
		(*polish)[(*k)++] = ft_strdup(de_stack(stack));
	else
		de_stack(stack);
}

void	init_polish(char ***polish, char ***stack, char **infix)
{
	int		size;
	int		i;

	size = find_size(infix);
	if (!((*stack) = (char **)malloc(sizeof(char *) * (size + 1))))
		return ;
	i = 0;
	while (i < size)
		(*stack)[i++] = NULL;
	if (!((*polish) = (char **)malloc(sizeof(char *) * (size + 1))))
		return ;
	i = 0;
	while (i < size)
		(*polish)[i++] = NULL;
}

void	destack_par(char ***polish, char ***stack, int *k)
{
	while (ft_strcmp(t_s(*stack), "(") != 0)
		(*polish)[(*k)++] = de_stack(stack);
	de_stack(stack);
}

int		helper_polish(char ***polish, char ***s, char **in)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (in[i])
	{
		if (ft_strcmp(in[i], ")") == 0)
			destack_par(polish, s, &k);
		else if (is_operator(in[i]))
		{
			if (ft_strcmp(in[i], "(") == 0 || f_prio(in[i]) > f_prio(t_s(*s)))
				add_stack(s, in[i]);
			else
			{
				while (f_prio(in[i]) <= f_prio(t_s(*s)))
					destack_prio(polish, s, &k);
				add_stack(s, in[i]);
			}
		}
		else
			(*polish)[k++] = ft_strdup(in[i]);
		i++;
	}
	return (k);
}

char	**parse_polish(char **infix)
{
	char	**polish;
	char	**stack;
	int		k;

	init_polish(&polish, &stack, infix);
	k = helper_polish(&polish, &stack, infix);
	while ((polish[k] = de_stack(&stack)))
		k++;
	return (polish);
}
