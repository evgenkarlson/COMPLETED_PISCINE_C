/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 20:48:59 by varnaud           #+#    #+#             */
/*   Updated: 2016/09/27 20:54:25 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	char	*tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while ((*tmp++ = *src++))
		;
	return (dest);
}
