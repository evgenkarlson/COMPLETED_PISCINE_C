/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/23 12:07:37 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	char *filename;
	char *dict;
	char *nbr;

	filename = 0;
	dict = 0;
	nbr = 0;
	if (ft_ver_cond(argc, argv) >= 1)
	{
		filename = ft_dict_file(argc, argv);
		dict = ft_read_dict(filename);
		ft_get_nbr(argc, argv, &nbr);
		ft_write_nbr(nbr, dict);
		ft_free(filename, dict, nbr);
	}
	else
		ft_msg_error();
	write(1, "\n", 1);
	return (0);
}
