/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 14:58:06 by varnaud           #+#    #+#             */
/*   Updated: 2016/09/27 16:39:31 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*d;
	const char		*s;

	d = dest;
	s = src;
	while (n--)
	{
		*d++ = *s;
		if (*s == c)
			return ((void*)d);
		s++;
	}
	return (NULL);
}
