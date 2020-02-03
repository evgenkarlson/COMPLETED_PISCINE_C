/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 23:17:43 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/17 13:53:16 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				con;

	i = 0;
	con = 1;
	while (con)
	{
		if (src[i] == '\0' || i == n - 1)
		{
			con = 0;
			if (i < n - 1)
				dest[i + 1] = '\0';
		}
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
