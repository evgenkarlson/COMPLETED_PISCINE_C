/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:19:49 by cromalde          #+#    #+#             */
/*   Updated: 2020/11/08 16:39:38 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_is_spaced(char c);

char	*ft_strchar(char *str, char to_find)
{
	int	i;
	int k;
	int	count;

	i = 0;
	k = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == to_find)
		{
			count++;
			k = i;
		}
		if (count == 1)
			return (str + i);
		i++;
	}
	if (count == 1)
		return (str + k);
	return ((void *)0);
}

char	*ft_cinstr(char *str)
{
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == 32)
			str++;
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			str++;
		if (((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			return (str);
	}
	return (str);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		while (str[i + k] == to_find[k])
		{
			if ((to_find[k + 1] == '\0') && ft_is_spaced(str[i + k + 1]))
				return (str + i);
			k++;
		}
		k = 0;
		i++;
	}
	return ((void *)0);
}

char	*ft_insrc(char *str, char *to_find)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		while (str[i + k] == to_find[k])
		{
			if ((to_find[k + 1] == '\n') && ft_is_spaced(str[i + k + 1]))
				return (str + i);
			k++;
		}
		k = 0;
		i++;
	}
	return ((void *)0);
}
