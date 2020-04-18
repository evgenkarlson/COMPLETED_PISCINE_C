/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 23:37:45 by varnaud           #+#    #+#             */
/*   Updated: 2016/09/28 15:51:26 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	const char	*l;
	const char	*p;

	l = little;
	p = NULL;
	if (*l == '\0')
		return ((char*)big);
	while (*big)
	{
		if (p != NULL && *big == *l)
			l++;
		else
		{
			if (p != NULL)
				big = p + 1;
			p = NULL;
			l = little;
		}
		if (p == NULL && *big == *l && (*(p = big) || 1))
			l++;
		if (p != NULL && *l == '\0')
			return ((char*)p);
		big++;
	}
	return (*big == *l ? (char*)big : NULL);
}
