/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 01:43:15 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/24 14:57:38 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_getop(char *c)
{
	if (*c == '+')
		return (0);
	else if (*c == '-')
		return (1);
	else if (*c == '*')
		return (2);
	else if (*c == '/')
		return (3);
	else if (*c == '%')
		return (4);
	else
		return (5);
}

void	ft_do_op(int argc, char **argv)
{
	if (argc == 4)
	{
		int	(*g_p[5]) (int x, int y, int *error);
		int result;
		int op;

		g_p[0] = sum;
		g_p[1] = subtract;
		g_p[2] = mul;
		g_p[3] = div;
		g_p[4] = mod;
		op = ft_getop(argv[2]);
		if (op == 5)
		{
			ft_putchar('0');
			return;
		}
		result = (*g_p[op])(ft_atoi(argv[1]), ft_atoi(argv[3]), &op);
		if (!op)
			ft_putnbr(result);
	}
}
