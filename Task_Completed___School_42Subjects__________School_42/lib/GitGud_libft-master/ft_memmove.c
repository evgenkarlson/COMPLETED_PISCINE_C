/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:46:24 by varnaud           #+#    #+#             */
/*   Updated: 2016/09/28 17:52:17 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (s == d)
		return (dest);
	if (s < d)
	{
		s = s + n - 1;
		d = d + n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
