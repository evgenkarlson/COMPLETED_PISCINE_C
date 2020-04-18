/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 17:14:15 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/30 17:30:02 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long nbr, int base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr <= -base)
			ft_putnbr_base(nbr / -base, base);
		ft_putchar(ft_itoc(-(nbr % base)));
	}
	else if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, base);
		ft_putchar(ft_itoc(nbr % base));
	}
	else
		ft_putchar(ft_itoc(nbr % base));
}
