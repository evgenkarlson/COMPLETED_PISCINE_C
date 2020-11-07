/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:31 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:18:42 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	read_file(char *file, int hex_display)
{
	if (file == NULL)
		return ;
	ft_print_memory(file, ft_strlen(file), hex_display);
	free(file);
}
