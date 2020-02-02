/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 10:37:52 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/25 10:37:53 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_lib.h"

#define BUFF_SIZE	4096

void	ft_display_stdin(int file)
{
	char	buffer[BUFF_SIZE + 1];

	while (read(file, buffer, BUFF_SIZE))
		ft_putstr(buffer);
}
