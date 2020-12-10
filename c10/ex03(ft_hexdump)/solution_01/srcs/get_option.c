/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:22 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:13:37 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int		get_option(int argc, char **argv, int *index)
{
	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[1], "-C") == 0)
	{
		*index += 1;
		return (1);
	}
	return (0);
}
