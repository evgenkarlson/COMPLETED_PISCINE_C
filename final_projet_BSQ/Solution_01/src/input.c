/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 10:45:47 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/01 16:50:32 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

t_uns	read_file(char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (prepare_read(&fd) == 1)
		return (1);
	return (0);
}

t_uns	read_stdin(void)
{
	int		fd;

	fd = 0;
	if (prepare_read(&fd))
		return (1);
	return (0);
}
