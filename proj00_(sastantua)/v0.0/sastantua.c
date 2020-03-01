/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 04:12:29 by jmarin-h          #+#    #+#             */
/*   Updated: 2015/10/18 23:40:33 by jmarin-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SMALL(a, b) ((a < b) ? a : b)
#define NB_LINES(a) (2 * a + a * (a + 1) / 2)
#define DOOR_SIZE(a) (a - ((a % 2) ? 0 : 1))

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnchar(char c, int n)
{
	while (n--)
		ft_putchar(c);
}

void	ft_draw_line(int line, int size, int stars, int spaces)
{
	ft_putnchar(' ', spaces);
	ft_putchar('/');
	if (line >= NB_LINES(size) - DOOR_SIZE(size))
	{
		ft_putnchar('*', stars - (DOOR_SIZE(size) - 1) / 2);
		if (size >= 5 && line == NB_LINES(size) - DOOR_SIZE(size) / 2 - 1)
		{
			ft_putnchar('|', DOOR_SIZE(size) - 2);
			ft_putchar('$');
			ft_putchar('|');
		}
		else
			ft_putnchar('|', DOOR_SIZE(size));
		ft_putnchar('*', stars - (DOOR_SIZE(size) - 1) / 2);
	}
	else
		ft_putnchar('*', stars * 2 + 1);
	ft_putchar('\\');
	ft_putchar('\n');
}

void	sastantua(int size)
{
	int		i;
	int		star_counter;
	int		stage;
	int		line;
	int		stars[NB_LINES(size)];

	i = 0;
	stage = 1;
	star_counter = 0;
	while (stage++ <= size)
	{
		line = 1;
		while (line++ < (stage + 2))
		{
			stars[i] = star_counter;
			star_counter++;
			i++;
		}
		star_counter += ((stage % 2) ? (stage - 1) / 2 : stage / 2) + 1;
	}
	i = -1;
	while (++i < NB_LINES(size))
		ft_draw_line(i, size, stars[i], stars[NB_LINES(size) - 1] - stars[i]);
}

int		main(void)
{
	sastantua(5);
	return (0);
}
