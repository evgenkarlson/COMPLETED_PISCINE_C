/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:02:07 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:19:51 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void	ft_destroy(void **array)
{
	int	y;

	y = -1;
	while (array[++y])
		free(array[y]);
	free(array[y]);
	free(array);
}
