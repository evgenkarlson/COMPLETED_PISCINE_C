/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_lib.h"

int		ft_atoi(char *str)		/* Функция получает из строки и возвращает целое число */
{
	int	i;
	int	negativ;
	int	number;

	i = 0;
	negativ = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negativ = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + ((int)str[i] - '0');
		i++;
	}
	if (negativ == 1)
		return (-number);
	else
		return (number);
}

void	ft_print_name(int i, int argc, char *argv)
{
	if (argc >= 4)
	{
		if (i > 3)
			ft_putstr("\n==> ");
		else
			ft_putstr("==> ");
		ft_putstr(argv);
		ft_putstr(" <==\n");
	}
}

int		ft_size_file(char *argv)
{
	int		fd;
	char	buffer;
	int		size;
	int		r;

	size = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_display_custom_error(errno, argv);
	else
	{
		while (r = read(fd, &buffer, 1))
		{
			if (r == -1)
			{
				ft_display_custom_error(errno, argv);
				break;
			}
			size++;
		}
		if (close(fd) == -1)
			ft_display_custom_error(errno, argv);
	}
	return (size);
}


void	ft_disp_file(int i, int fd, int argc, char **argv)
{
	char	buffer;
	int		offset;
	int		readed;
	int		size_file;

	size_file = ft_size_file(argv[i]);
	readed = 0;
	ft_print_name(i, argc, argv);
	if (argv[1][0] == '-' && (argv[1][1] == 'C' || argv[1][1] == 'c'))
	{
		offset = ft_atoi(argv[2]);
		while (readed != offset - 1)
			readed += read(fd, &buffer, 1);
		while (read(fd, &buffer, 1))
			write(1, &buffer, 1);
	}
	else
	{
		offset = 10;
		while (readed < (size_file - offset))
			readed += read(fd, &buffer, 1);
		while  (read(fd, &buffer, 1))
			write(1, &buffer, 1);
	}
}

void	ft_tail(int argc, char **argv)
{
	int		fd;
	int		i;

	g_progname = argv[0];
	i = 3;
	if (argc >= 4)
	{
		while (i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
				ft_display_custom_error(errno, argv[i]);
			else
			{
				ft_disp_file(i, fd, argc, argv[i]);
				if (close(fd) == -1)
					ft_display_custom_error(errno, argv[i]);
			}
			i++;
		}
	}
}

int		main(int argc, char **argv)	/* Принимаем количество аргументов и адресс массва строк с аргументами программы */
{
	ft_tail(argc, argv);			/* Запускаем функцию печати последних 10 строк файлов, на которые указывают аргументы в 
									** массиве строк '**argv', отправляя в функцию размер массива строк и его адресс */
	return (0);						/* Завершаем главную функцию и возвращаем ноль, в знак того что все прошло успешно */
}