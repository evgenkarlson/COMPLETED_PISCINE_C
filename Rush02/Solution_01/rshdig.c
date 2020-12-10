/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rshdig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/23 12:07:26 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_write_uni(char dig, char *dict)
{
	int		d;
	int		i;
	char	write_dig[20];

	d = 0;
	i = 0;
	while (dict[d] != '\0')
	{
		if (ft_if_uni(dig, dict, d) == 1)
		{
			while (dict[d] != '\n')
			{
				if (dict[d] != ' ' && dict[d] != ':' &&
					!(dict[d] >= '0' && dict[d] <= '9'))
				{
					write_dig[i] = dict[d];
					i++;
				}
				d++;
			}
			write_dig[i] = '\0';
		}
		d++;
	}
	ft_putstr(write_dig);
}

void	ft_write_dez(char dig, char *dict)
{
	int		d;
	int		i;
	char	write_dig[20];

	d = 0;
	i = 0;
	while (dict[d] != '\0')
	{
		if (ft_if_dez(dig, dict, d) == 1)
		{
			while (dict[d] != '\n')
			{
				if (dict[d] != ' ' && dict[d] != ':' &&
					!(dict[d] >= '0' && dict[d] <= '9'))
				{
					write_dig[i] = dict[d];
					i++;
				}
				d++;
			}
			write_dig[i] = '\0';
		}
		d++;
	}
	ft_putstr(write_dig);
}

void	ft_write_teens(char dig, char *dict)
{
	int		d;
	int		i;
	char	write_dig[200];

	d = 0;
	i = 0;
	while (dict[d] != '\0')
	{
		if (ft_if_teens(dig, dict, d) == 1)
		{
			while (dict[d] != '\n')
			{
				if (dict[d] != ' ' && dict[d] != ':' &&
					!(dict[d] >= '0' && dict[d] <= '9'))
				{
					write_dig[i] = dict[d];
					i++;
				}
				d++;
			}
			write_dig[i] = '\0';
		}
		d++;
	}
	ft_putstr(write_dig);
}
