/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 12:31:31 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/11 06:39:19 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memadd(void **dest, void *src, size_t dest_size, size_t src_size)
{
	unsigned char	*p;
	unsigned char	*s;

	if (dest_size + src_size == 0)
		return (NULL);
	s = src;
	p = (unsigned char*)malloc(dest_size + src_size);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, *dest, dest_size);
	while (src_size)
	{
		src_size--;
		p[src_size + dest_size] = s[src_size];
	}
	free(*dest);
	*dest = p;
	return ((void*)p);
}
