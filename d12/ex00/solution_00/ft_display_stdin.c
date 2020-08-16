/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_display_stdin(int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		len;
	
	while ((len = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[len] = '\0';
		ft_putstr(buffer);
	}
}

/*	second solution - v2.0

void	ft_display_stdin(int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		nb_char;

	while (nb_char = read(fd, buffer, BUFF_SIZE))
		write(1, buffer, nb_char);
	write(1, "\n", 1);
}

*/