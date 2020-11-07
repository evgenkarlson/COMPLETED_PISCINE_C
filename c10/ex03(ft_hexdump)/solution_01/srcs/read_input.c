/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:31 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:18:49 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	read_input(int hex_display)
{
	int		read_amount;
	char	buffer[BUFSIZE];
	char	*output;

	output = malloc(1);
	output[0] = 0;
	while ((read_amount = read(0, buffer, BUFSIZE)) > 0)
		concat_strings(&output, buffer, read_amount);
	read_file(output, hex_display);
}
