/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:24:26 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/21 20:10:34 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "utilities.h"

t_bool	ft_read_full(int fd, char **file_content, UINT *total)
{
	char		buffer[SIZE_3M];
	UINT		byte_read;

	if (read(fd, 0, 0) == -1)
		return (false);
	*total = 0;
	*file_content = NULL;
	while ((byte_read = read(fd, buffer, SIZE_3M)) > 0)
	{
		if (!(*file_content = ft_extend_array(*file_content,
				buffer, *total, *total + byte_read)))
			return (false);
		(*total) += byte_read;
	}
	if (byte_read == 0)
		return (true);
	return (false);
}
