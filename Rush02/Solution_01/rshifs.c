/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rshifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/23 12:07:22 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_if_uni(char dig, char *dict, int d)
{
	if (dict[d] == dig && !(dict[d + 1] >= '0' && dict[d + 1] <= '9') &&
			!(dict[d - 1] >= '0' && dict[d - 1] <= '9'))
		return (1);
	else
		return (0);
}

int		ft_if_dez(char dig, char *dict, int d)
{
	if (dict[d] == dig && (dict[d + 1] == '0') &&
		!(dict[d + 2] >= '0' && dict[d + 2] <= '9') &&
		!(dict[d - 1] >= '0' && dict[d - 1] <= '9'))
		return (1);
	else
		return (0);
}

int		ft_if_teens(char dig, char *dict, int d)
{
	if (dict[d] == dig && dict[d] == '1' &&
		(dict[d + 1] >= '0' && dict[d + 1] <= '9') &&
		!(dict[d + 2] >= '0' && dict[d + 2] <= '9') &&
		!(dict[d - 1] >= '0' && dict[d - 1] <= '9'))
		return (1);
	else
		return (0);
}
