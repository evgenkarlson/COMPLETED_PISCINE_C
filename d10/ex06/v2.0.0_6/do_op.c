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

#include "do_op.h"

int	getop(char *c)
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
		return (9999);
}

int	main(int argc, char **argv)
{
	int result;
	int op;

	g_p[0] = sum;
	g_p[1] = subtract;
	g_p[2] = mul;
	g_p[3] = div;
	g_p[4] = mod;
	if (argc != 4)
		return (0);
	else
	{
		op = getop(argv[2]);
		if (op == 9999)
		{
			ft_putstr("0\n");
			return (0);
		}
		result = (*g_p[op])(ft_atoi(argv[1]), ft_atoi(argv[3]));
		if (!g_div && !g_mod)
			ft_putnbr(result);
		ft_putchar('\n');
		return (0);
	}
}
