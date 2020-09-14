/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_display_file(char *argv)
{
	int		r;
	int 	fd;
	char	buffer[BUF_SIZE + 1];

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putstr("\n");
		ft_display_custom_error(errno, argv);
	}
	else
	{
		while ((r = read(fd, buffer, BUF_SIZE)))
		{
			if (r == -1)
			{
				ft_display_custom_error(errno, argv);
				break;
			}
			else
			{
				buffer[r] = '\0';
				ft_putstr(buffer);
			}
		}
		if ((close(fd)) == -1)
		{
			ft_putstr("\n");
			ft_display_custom_error(errno, argv);
		}
	}
}