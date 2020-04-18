/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 22:05:23 by varnaud           #+#    #+#             */
/*   Updated: 2016/09/28 22:32:03 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	end = start;
	while (s[end] != '\0')
		end++;
	end--;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
