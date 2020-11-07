/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastanua.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:30:23 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 15:08:03 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchars(char c, int n)
{
	while (n--)
		ft_putchar(c);
}

int		calc_w(int n)
{
	if (n == 0)
		return (3);
	return (calc_w(n - 1) + (n + 3) * 3 / 2);
}

void	door_row(int center, int w, int i, int door_s)
{
	ft_putchars(' ', center - w + i - 1);
	ft_putchar('/');
	if (i <= door_s)
	{
		ft_putchars('*', w - i - door_s / 2);
		if (door_s > 4 && i == door_s / 2 + 1)
		{
			ft_putchars('|', door_s - 2);
			ft_putchar('$');
			ft_putchar('|');
		}
		else
			ft_putchars('|', door_s);
		ft_putchars('*', w - i - door_s / 2);
	}
	else
	{
		ft_putchars('*', w - i);
		ft_putchar('*');
		ft_putchars('*', w - i);
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	draw_layer_w_door(int center, int n, int door_needed)
{
	int door_s;
	int w;
	int i;

	w = calc_w(n);
	if (door_needed)
		door_s = n / 2 * 2 + 1;
	else
		door_s = 0;
	i = n + 4;
	while (--i)
	{
		door_row(center, w, i, door_s);
	}
}

void	sastantua(int size)
{
	int i;
	int center;

	if (size > 0)
	{
		center = calc_w(size - 1);
		i = 0;
		while (i < size)
		{
			draw_layer_w_door(center, i, i == size - 1);
			i++;
		}
	}
}

int		main(void)
{
	sastantua(5);
	return (0);
}