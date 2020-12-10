/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:31 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:18:47 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int		main(int argc, char **argv)
{
	int		i;
	int		hex_display;

	i = 1;
	hex_display = get_option(argc, argv, &i);
	if (argc == 1 || (argc == 2 && hex_display))
		read_input(hex_display);
	else if (i + 1 != argc)
		read_argument_files(argc, argv, i, hex_display);
	else
		read_single_file(argv, i, hex_display);
	return (0);
}
