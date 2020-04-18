/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:26:57 by varnaud           #+#    #+#             */
/*   Updated: 2016/09/28 21:52:53 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	fresh = ft_strnew(len);
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	return (fresh);
}
