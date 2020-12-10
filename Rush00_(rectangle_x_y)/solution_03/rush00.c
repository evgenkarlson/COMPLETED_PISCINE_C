/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clseyer <clseyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/06 18:40:38 by clseyer           #+#    #+#             */
/*   Updated: 2014/07/06 18:50:58 by clseyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		jp_putchar(char c);
void	jp_hd_ft(char d, char m, char f, int l);

void	rush(int x, int y)
{
	int i;

	i = 0;
	if (x > 0 && y > 0)
	{
		jp_hd_ft('o', '-', 'o', x);
		if (y > 2)
		{
			while (i < (y - 2))
			{
				jp_hd_ft('|', ' ', '|', x);
				i++;
			}
		}
		if (y > 1)
		{
			jp_hd_ft('o', '-', 'o', x);
		}
	}
}

void	jp_hd_ft(char d, char m, char f, int l)
{
	int i;

	i = 0;
	jp_putchar(d);
	while (i < (l - 2))
	{
		jp_putchar(m);
		i++;
	}
	if (l > 1)
	{
		jp_putchar(f);
	}
	jp_putchar('\n');
}
