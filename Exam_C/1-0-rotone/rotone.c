/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:10:52 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 10:32:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] > 64 && argv[1][i] < 90)
				argv[1][i]++;
			else if (argv[1][i] > 96 && argv[1][i] < 122)
				argv[1][i]++;
			else if (argv[1][i] == 90 || argv[1][i] == 122)
				argv[1][i] -= 25;
			i++;
		}
		ft_putstr(argv[1]);
		ft_putchar('\n');
	}
}
