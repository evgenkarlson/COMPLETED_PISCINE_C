/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE	4096

int		main(int argc, char **argv)
{
	char	buffer[BUFF_SIZE + 1];
	int		file;
	int		nb_char;

	if (argc < 2)
		return (write(2, "File name missing.\n", 19) || 1);
	if (argc > 2)
		return (write(2, "Too many arguments.\n", 20) || 1);
	else
	{
		if ((file = open(argv[1], O_RDONLY)) == -1)
			return (write(2, "OPEN() error.\n", 14) || 1);
		nb_char = 1;
		while (nb_char)
		{
			nb_char = read(file, buffer, BUFF_SIZE);
			write(1, buffer, nb_char);
		}
		write(1,"\n", 1);
		if (close(file) == -1)
			return (write(2, "CLOSE() error.\n", 15) || 1);
	}
	return (0);
}