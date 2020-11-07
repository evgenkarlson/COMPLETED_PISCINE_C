/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:18:31 by lkinzel           #+#    #+#             */
/*   Updated: 2020/10/19 15:07:48 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int g_rows = 0;
int g_n = 0;
int g_n_uneven = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_r_w(int row)
{
	int data[4];
	int step;
	int c;

	c = 1;
	data[1] = 0;
	data[0] = 3 + (row - 1) * 2;
	data[3] = 4;
	step = 3;
	data[2] = 3;
	while (c <= row)
	{
		if (c == step + 1)
		{
			if (data[1] != 0 && data[1] % 2 == 0)
				data[3] += 2;
			data[0] += data[3];
			step += data[2] + 1;
			data[2]++;
			data[1]++;
		}
		c++;
	}
	return (data[0]);
}

void	with_doorknob(int o, int door_width, int cr)
{
	if (cr == g_rows - door_width / 2 && o == door_width - 2)
		ft_putchar('$');
	else
		ft_putchar('|');
}

void	row_with_door(int n, int cr, int o)
{
	int door_width;

	door_width = n;
	if (door_width % 2 == 0)
		door_width--;
	while (o < ((ft_r_w(cr) - 2 - door_width) / 2))
	{
		ft_putchar('*');
		o++;
	}
	o = 0;
	while (o < door_width)
	{
		if (g_n > 4)
			with_doorknob(o, door_width, cr);
		else
			ft_putchar('|');
		o++;
	}
	o = 0;
	while (o < ((ft_r_w(cr) - 2 - door_width) / 2))
	{
		ft_putchar('*');
		o++;
	}
}

void	ft_print(int cr, int spaces[], int o, int n)
{
	spaces[0] = ft_r_w(g_rows) - ft_r_w(g_rows) / 2;
	while (cr <= g_rows)
	{
		o = 0;
		spaces[1] = spaces[0] - ((ft_r_w(cr) - ft_r_w(1)) / 2) - 1;
		while (o < spaces[1])
		{
			ft_putchar(' ');
			o++;
		}
		ft_putchar('/');
		o = 0;
		if (cr == g_rows || spaces[1] < g_n_uneven)
			row_with_door(n, cr, 0);
		else
			while (o < ft_r_w(cr) - 2)
			{
				ft_putchar('*');
				o++;
			}
		ft_putchar('\\');
		ft_putchar('\n');
		cr++;
	}
}

void	sastantua(int n)
{
	int spaces[2];

	
	if (n > 0)
	{
		g_n = n;
		if (g_n % 2 == 1)
			g_n_uneven = g_n + 1;
		else
			g_n_uneven = g_n;
		n = 0;
		g_rows = g_n * 3;
		while (n < g_n)
		{
			g_rows += n;
			n++;
		}
		ft_print(1, spaces, 0, g_n);
	}
}
