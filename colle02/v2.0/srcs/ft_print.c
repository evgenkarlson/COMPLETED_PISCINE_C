/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbufnoir <rbufnoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 22:20:24 by rbufnoir          #+#    #+#             */
/*   Updated: 2014/07/20 22:55:11 by rbufnoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void	jp_putchar(char c)
{
	write(1, &c, 1);
}

void	jp_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	jp_show(int nb, int arg1, int arg2, int test)
{
	if (test == 1)
		jp_putstr(" || ");
	jp_putstr("[colle-0");
	jp_putchar(nb + '0');
	jp_putstr("] [");
	jp_putchar(arg1 + '0');
	jp_putstr("] [");
	jp_putchar(arg2 + '0');
	jp_putstr("]\n");
}

int		jp_test_tab(int *tab)
{
	int i;

	while (i < 5)
	{
		if (tab[i] == 1)
			return (1);
		i++;
	}
	return (0);
}
