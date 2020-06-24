/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <adespond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 00:31:57 by adespond          #+#    #+#             */
/*   Updated: 2015/09/16 20:11:33 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_adv_opp.h"

int		ft_add(int a, int b)
{
	return (a + b);
}

int		ft_sub(int a, int b)
{
	return (a - b);
}

int		ft_mul(int a, int b)
{
	return (a * b);
}

int		ft_mod(int a, int b)
{
	return (a % b);
}

int		ft_div(int a, int b)
{
	return (a / b);
}

int		ft_usage(int a, int b)
{
	ft_putstr("error : only [ - + * / % ] are accepted.");
	return (a + b);
}