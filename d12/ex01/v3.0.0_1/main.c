/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 14:37:09 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/17 19:24:40 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	jp_putchar(char c)
{
	write(1, &c, 1);
}

void	jp_putstr(char *str)
{
	while (*str != '\0')
		jp_putchar(*str++);
}

int		jp_cat(char *filename)
{
	int		fh;
	char	buf[129];
	int		len;

	if ((fh = open(filename, O_RDONLY)) == -1)
		return (errno);
	while ((len = read(fh, buf, 128)))
	{
		buf[len] = '\0';
		jp_putstr(buf);
	}
	close(fh);
	return (0);
}

void	jp_puterr(char *name, char *file, int no)
{
	if (no != 0)
	{
		jp_putstr(name);
		jp_putstr(": ");
		jp_putstr(file);
		jp_putstr(": ");
		if (no == ENOENT)
			jp_putstr("No such file or directory\n");
	}
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			jp_puterr(argv[0], argv[i], jp_cat(argv[i]));
			i++;
		}
		return (0);
	}
	else
	{
		jp_putchar('\\');
		return (1);
	}
}
