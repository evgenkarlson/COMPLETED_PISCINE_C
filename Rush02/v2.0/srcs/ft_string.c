/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbufnoir <rbufnoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 14:22:13 by rbufnoir          #+#    #+#             */
/*   Updated: 2014/07/20 16:30:47 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*jp_strcpy(char *dest, char *src)
{
	while (*src != '\0')
		*dest++ = *src++;
	*(dest) = '\0';
	return (dest);
}

char	*jp_strcat(char *dest, char *src)
{
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
		*dest++ = *src++;
	*(dest) = '\0';
	return (dest);
}
