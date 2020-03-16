/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:25:49 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:25:50 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_positive(int nb)
{
	int a;
	int b;

	if (!nb)
		return ;
	a = nb / 10;
	b = nb - a * 10;
	ft_put_positive(a);
	ft_putchar('0' + b);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(-2);
		ft_putnbr(147483648);
		return ;
	}
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		ft_put_positive(-nb);
		return ;
	}
	ft_put_positive(nb);
}

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (1)
	{
		c = *(str + i);
		if (c == '\0')
			break ;
		ft_putchar(c);
		i++;
	}
}
