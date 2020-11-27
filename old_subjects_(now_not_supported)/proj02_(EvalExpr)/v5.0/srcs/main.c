/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:58:30 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 22:24:45 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		eval_expr(char *str)
{
	char	**infix;
	char	**polish;
	int		res;

	if (!str[0])
		return (0);
	infix = parse_str(str);
	if (find_size(infix) <= 1)
		return (ft_atoi(infix[0]));
	else
	{
		polish = parse_polish(infix);
		res = calc_polish(polish);
	}
	return (res);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
