/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 19:24:12 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/19 22:10:01 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	const char	*p;

	if (s == NULL)
		return (0);
	p = s;
	while (*p)
		p++;
	return (p - s);
}
