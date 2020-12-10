/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argument_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:31 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:17:06 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	read_argument_files(int argc, char **argv, int i, int hex_display)
{
	char	*file;
	char	*tmp;

	file = malloc(2);
	file[0] = 0;
	while (i < argc)
	{
		if (file_exists(argv[i]) < 0)
			print_error_message(file_exists(argv[i]), argv[i]);
		else
		{
			tmp = get_file(argv[i]);
			if (tmp == NULL)
				return ;
			concat_strings(&file, tmp, ft_strlen(tmp));
		}
		i++;
	}
	read_file(file, hex_display);
}
