/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: IHaveNoClueI <ctfx337@gmail.com>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/13 13:55:54 by IHaveNoClueI   #+#    #+#                */
/*   Updated: 2018/10/13 13:55:56 by IHaveNoClueI  ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
return (0);
}
