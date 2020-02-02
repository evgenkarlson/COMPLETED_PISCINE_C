/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 02:43:26 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/26 23:44:20 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	norme_helper2(int **tab, char *str_no_information, char *finalstring)
{
	make_it_numbers(&tab, str_no_information, g_height, 1);
	find_biggest(tab, str_no_information);
	free(tab);
	make_it_numbers(&tab, str_no_information, g_height, 0);
	finalstring = transform_to_string(tab, g_pos, g_dim);
	ft_putstr(finalstring);
	free(tab);
}

void	norme_helper(char *str, t_ptr head, int fd)
{
	char	*str_no_information;
	int		**tab;
	char	*finalstring;

	freelist(&head);
	str_no_information = (char*)malloc(sizeof(char) * ft_strlen(str));
	str_no_information = get_information(str);
	tab = NULL;
	finalstring = NULL;
	if (ft_strcmp(str_no_information, "error") != 0)
		norme_helper2(tab, str_no_information, finalstring);
	free(str);
	if (close(fd) == -1)
		ft_putstr("closing failed\n");
}

void	runstdi(char ch)
{
	int		fd;
	int		i;
	char	*str;
	t_ptr	head;
	int		n;

	i = 1;
	fd = 0;
	head = NULL;
	n = 0;
	while (read(0, &ch, 1) > 0)
	{
		insert(&head, ch);
		n++;
	}
	str = (char*)malloc(sizeof(char) * (n + 1));
	fill_str(head, str);
	norme_helper(str, head, fd);
}

void	runfiles(int argc, char **argv, int fd, int i)
{
	char	buf[BUF_SIZE + 1];
	char	*str;
	int		ret;
	t_ptr	head;
	int		n;

	i = 1;
	fd = 0;
	while (i < argc)
	{
		n = 0;
		head = NULL;
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_putstr("opening file failed\n");
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			insert(&head, buf[0]);
			n++;
		}
		str = (char*)malloc(sizeof(char) * (n + 1));
		fill_str(head, str);
		norme_helper(str, head, fd);
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	ch;

	ch = '\0';
	if (argc == 1)
		runstdi(ch);
	else
		runfiles(argc, argv, 0, 0);
	return (0);
}
