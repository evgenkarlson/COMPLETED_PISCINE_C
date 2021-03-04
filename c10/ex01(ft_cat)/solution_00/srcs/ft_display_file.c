/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/03/03 11:15:10 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_display_file(char *argv)
{
	int		r;
	int 	fd;
	char	buffer;

	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_display_custom_error(errno, argv);
	else
	{
		while ((r = read(fd, &buffer, 1)))
		{
			if (r == -1)
			{
				ft_display_custom_error(errno, argv);
				break;
			}
			else
				write(1, &buffer, 1);
		}
		if ((close(fd)) == -1)
			ft_display_custom_error(errno, argv);
	}
}