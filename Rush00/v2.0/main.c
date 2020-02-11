/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/05 09:50:59 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/19 15:34:38 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		jp_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	colle(int x, int y);

int		col_atoi(char *str)
{
	int		val;
	int		neg;

	val = 0;
	neg = 0;
	if (*str == '-')
		neg = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			val = (val * 10) + (*str - '0');
		else
			break;
		str++;
	}
	return ((val > 0 && neg == 1 ? -val : val));
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		colle(col_atoi(argv[1]), col_atoi(argv[2]));
	return (0);
}
