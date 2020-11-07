/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:43 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:13:41 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int		file_exists(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (fd);
	close(fd);
	return (1);
}
