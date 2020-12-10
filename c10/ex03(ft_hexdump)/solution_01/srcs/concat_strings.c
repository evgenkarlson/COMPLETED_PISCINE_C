/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:43 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:12:26 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	concat_strings(char **dest, char *src, int amount)
{
	int		i;
	int		dest_len;
	char	*tmp;

	dest_len = 0;
	while ((*dest)[dest_len])
		dest_len++;
	if ((tmp = malloc(dest_len + amount + 1)) == NULL)
		return ;
	i = 0;
	while (i < dest_len)
	{
		tmp[i] = (*dest)[i];
		i++;
	}
	i = 0;
	while (i < amount)
	{
		tmp[dest_len + i] = src[i];
		i++;
	}
	tmp[dest_len + i] = '\0';
	free(*dest);
	*dest = tmp;
}