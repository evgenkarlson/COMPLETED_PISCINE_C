/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 00:02:36 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

int		ft_size_file(char *argv)
{
	int		fd;
	char	buffer;
	int		size;
	int		r;

	size = 0;
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
			size++;
		}
		if (close(fd) == -1)
			ft_display_custom_error(errno, argv);
	}
	return (size);
}