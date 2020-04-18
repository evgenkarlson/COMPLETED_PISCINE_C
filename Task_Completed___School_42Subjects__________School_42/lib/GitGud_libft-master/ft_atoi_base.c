/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:22:03 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/04 16:59:00 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *s, int b)
{
	int		n;
	int		negative;
	int		i;
	int		exp;

	exp = 0;
	i = 0;
	negative = 1;
	n = 0;
	if (*s == '-')
	{
		i++;
		negative = -1;
	}
	while (s[i])
		i++;
	while (--i >= 0)
	{
		if (ft_ctoi(s[i]) != -1 && ft_ctoi(s[i]) < b)
			n += ft_ctoi(s[i]) * ft_pow(b, exp++);
	}
	return (n * negative);
}
