/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_single_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:31 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:17:32 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	read_single_file(char **argv, int i, int hex_display)
{
	if (file_exists(argv[i]) < 0)
		print_error_message(file_exists(argv[i]), argv[i]);
	else
		read_file(get_file(argv[i]), hex_display);
}