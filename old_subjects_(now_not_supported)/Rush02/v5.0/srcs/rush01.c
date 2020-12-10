/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 00:17:03 by flklein           #+#    #+#             */
/*   Updated: 2018/09/16 01:44:35 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle2.h"

char	display_01(int x, int y, int a, int b)
{
	if (b == 1 && a == 1)
		return ('/');
	else if (b == 1 && a == x)
		return ('\\');
	else if (b == y && a == 1)
		return ('\\');
	else if (b == y && a == x)
		return ('/');
	else if (b == 1 || b == y)
		return ('*');
	else if (a == 1 || a == x)
		return ('*');
	else
		return (' ');
}

char	*rush_01(int x, int y)
{
	int		a;
	int		b;
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(char) * ((x + 1) * y + 1))))
		return (NULL);
	if (x > 0 && y > 0)
	{
		i = 0;
		b = 1;
		while (b >= 1 && b <= y)
		{
			a = 1;
			while (a >= 1 && a <= x)
			{
				str[i++] = display_01(x, y, a, b);
				a++;
			}
			str[i++] = ('\n');
			b++;
		}
		str[i] = '\0';
	}
	return (str);
}
