/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:48:57 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/21 12:50:53 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define IS_SPACE(c) (((c == ' ' || c == '\t' || c == '\n') ? 1 : 0))

int		g_words = 0;

int		calc_numberofwords(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!(g_words) && (!(IS_SPACE(str[i]))))
			g_words++;
		else if (IS_SPACE(str[i - 1]) && !(IS_SPACE(str[i])))
			g_words++;
		i++;
	}
	if (g_words)
		return (1);
	else
		return (0);
}

char	*createword(char *str, int i, int j)
{
	char	*word;
	int		o;

	o = 0;
	word = (char*)malloc(sizeof(char) * (j - i + 1));
	while (i < j)
	{
		word[o] = str[i];
		i++;
		o++;
	}
	word[o] = '\0';
	return (word);
}

int		g_j = 0;
int		g_i = 0;

char	**ft_split_whitespaces(char *str)
{
	char	**arr;
	int		index;

	index = 0;
	if (calc_numberofwords(str))
	{
		arr = (char**)malloc(sizeof(char*) * (g_words + 1));
		while (index < g_words)
		{
			while (IS_SPACE(str[g_i]) && (str[g_i] != '\0'))
				g_i++;
			g_j = g_i;
			while (!(IS_SPACE(str[g_j])) && (str[g_j] != '\0'))
				g_j++;
			arr[index] = createword(str, g_i, g_j);
			g_i = g_j + 1;
			index++;
		}
	}
	else
		arr = (char**)malloc(sizeof(char*));
	arr[index] = 0;
	return (arr);
}
