/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:22:50 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/26 18:38:05 by jboniwel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*transform_to_string(int **tab, int pos[2], int size)
{
	int		i;
	int		j;
	char	*str;

	str = (char*)malloc(sizeof(char) * g_strlength);
	i = 0;
	while (i < g_height)
	{
		j = 0;
		while (j < g_length)
		{
			if ((i >= pos[0] && i < pos[0] + size) && (j >= pos[1]
						&& j < pos[1] + size))
				ft_strcharcat(str, g_square);
			else if (tab[i][j] == 1)
				ft_strcharcat(str, g_obstacle);
			else
				ft_strcharcat(str, g_empty);
			j++;
		}
		ft_strcharcat(str, '\n');
		i++;
	}
	ft_strcharcat(str, '\0');
	return (str);
}
