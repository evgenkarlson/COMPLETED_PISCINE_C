/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:43 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:11:35 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*get_file(char *filename)
{
	int		fd;
	int		read_amount;
	char	buffer[BUFSIZE];
	char	*output;

	fd = open(filename, O_RDONLY);
	output = malloc(1);
	output[0] = 0;
	while (output && (read_amount = read(fd, buffer, BUFSIZE)) > 0)
		concat_strings(&output, buffer, read_amount);
	return (output);
}