/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/01 16:33:59 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_stdin(void)
{
	char	buffer;
	int		r;

	while ((r = read(0, &buffer, 1)))
	{
		if (r == -1)
		{
			ft_putstr((char *)ft_get_strerr(errno));
			break;
		}
		else
			write(1, &buffer, 1);
	}
}