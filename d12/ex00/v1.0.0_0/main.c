/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 23:03:21 by adespond          #+#    #+#             */
/*   Updated: 2015/09/18 00:17:28 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>


#define BUFF_SIZE	4096

int		main(int argc, char **argv)
{
	int		file;
	int		nb_char;
	char	buf[BUFF_SIZE + 1];

	nb_char = 1;
	if (argc < 2)
		return (write(2, "File name missing.\n", 19) || 1);
	if (argc > 2)
		return (write(2, "Too many arguments.\n", 20) || 1);
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		return (write(2, "OPEN() error.\n", 14) || 1);
	while (nb_char)
	{
		nb_char = read(file, buf, BUFF_SIZE);
		buf[BUFF_SIZE] = '\0';
		write(1, buf, nb_char);
	}
	file = close(file);
	if (file == -1)
		return (write(2, "CLOSE() error.\n", 15) || 1);
	return (0);
}
