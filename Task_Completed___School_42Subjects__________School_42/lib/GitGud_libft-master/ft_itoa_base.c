/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:53:25 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/05 16:44:38 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(int n, int b)
{
	char	*a;
	int		i;
	int		negative;

	negative = 0;
	a = (char*)malloc(sizeof(char) * 34);
	if (n == 0)
	{
		a[0] = '0';
		a[1] = '\0';
	}
	if (b == 10 && n < 0)
		negative = 1;
	i = 0;
	while (1)
	{
		a[i++] = ft_abs(n % b) > 9 ? ft_abs(n % b) + 55 : ft_abs(n % b)
		+ '0';
		if (!(n /= b))
			break ;
	}
	if (negative)
		a[i++] = '-';
	a[i] = '\0';
	return (ft_strrev(a));
}
