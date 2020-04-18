/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 17:59:27 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/19 22:15:30 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_stradd(char **dest, char *src)
{
	int		size;
	char	*s;

	size = ft_strlen(*dest) + ft_strlen(src) + 1;
	s = ft_strnew(size);
	if (s == NULL)
		return (NULL);
	if (*dest != NULL)
	{
		ft_strcpy(s, *dest);
		free(*dest);
	}
	ft_strcat(s, src);
	*dest = s;
	return (s);
}
