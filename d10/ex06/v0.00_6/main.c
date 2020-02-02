/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 18:06:01 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/23 18:06:02 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/ft.h"

void	do_op(int argc, char *argv[])
{
	int		result;

	result = ft_atoi(argv[1]);
	if (*argv[2] == '+')
		ft_putnbr(result += ft_atoi(argv[3]));
	else if (*argv[2] == '-')
		ft_putnbr(result -= ft_atoi(argv[3]));
	else if (*argv[2] == '*')
		ft_putnbr(result *= ft_atoi(argv[3]));
	else if (*argv[2] == '/')
		ft_putnbr(result /= ft_atoi(argv[3]));
	else if (*argv[2] == '%')
		ft_putnbr(result %= ft_atoi(argv[3]));
	else if (*argv[2] == '=')
		ft_putnbr(1);
	else
		write(1, "0", 1);
}

int		main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (*argv[3] == '0' && (*argv[2] == '/'))
			write(1, "Stop : division by zero\n", 24);
		else if (*argv[3] == '0' && (*argv[2] == '%'))
			write(1, "Stop : modulo by zero\n", 23);
		else
			do_op(argc, argv);
	}
	return (0);
}
