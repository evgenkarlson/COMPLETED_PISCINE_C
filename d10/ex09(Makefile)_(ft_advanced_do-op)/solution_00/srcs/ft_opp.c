/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_adv_do-op.h"

int		ft_add(int nbr1, int nbr2)
{
	return (nbr1 + nbr2);
}

int		ft_sub(int nbr1, int nbr2)
{
	return (nbr1 - nbr2);
}

int		ft_mul(int nbr1, int nbr2)
{
	return (nbr1 * nbr2);
}

int		ft_div(int nbr1, int nbr2)
{
	return ((nbr2 != 0) ? (nbr1 / nbr2) : 0);
}

int		ft_mod(int nbr1, int nbr2)
{
	return ((nbr2 != 0) ?( nbr1 % nbr2) : 0);
}

int		ft_usage(int a, int b)
{
	ft_putstr("error : only [ - + * / % ] are accepted.");
	return (a + b);
}