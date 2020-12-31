/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:22:42 by exam              #+#    #+#             */
/*   Updated: 2019/08/16 19:22:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_str.h"
#include "ft_is.h"

int		ft_split_whitespace_count_word(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (ft_is_whitespace(*str))
			str++;
		if (*str == '\0')
			break ;
		while (!ft_is_whitespace(*str) && *str != '\0')
			str++;
		count++;
	}
	return (count);
}

char	**ft_split_whitespace(char *str)
{
	int		index;
	int		word_count;
	char	*word_start;
	char	**array;

	word_count = ft_split_whitespace_count_word(str);
	if (!(array = malloc((word_count + 1) * sizeof(char *))))
		return (NULL);
	index = 0;
	while (*str)
	{
		while (ft_is_whitespace(*str))
			str++;
		if (*str == '\0')
			break ;
		word_start = str;
		while (!ft_is_whitespace(*str) && *str != '\0')
			str++;
		array[index] = ft_str_n_duplicate(word_start, str - word_start);
		index++;
	}
	array[index] = 0;
	return (array);
}
