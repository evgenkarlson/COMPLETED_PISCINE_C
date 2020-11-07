/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 12:42:08 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/23 18:38:43 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		jp_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*jp_strcpy(char *dest, char *src)
{
	while (*src != '\0')
		*dest++ = *src++;
	*(dest) = '\0';
	return (dest);
}

char	*jp_strcat(char *dest, char *src)
{
	jp_strcpy(&dest[jp_strlen(dest)], src);
	return (dest);
}
