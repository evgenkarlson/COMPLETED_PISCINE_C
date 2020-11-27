/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:34:36 by flklein           #+#    #+#             */
/*   Updated: 2018/09/19 14:20:13 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_read_file(char *file)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		r;
	char	*str;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	else
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		while ((r = read(fd, buf, BUF_SIZE)))
		{
			buf[r] = '\0';
			str = ft_strjoin(str, buf);
		}
	}
	if ((r = close(fd)) == -1)
		return (NULL);
	return (str);
}

int		ft_display_error(void)
{
	ft_putstr_err("map error\n");
	return (0);
}

int		start_bsq(char *file_name)
{
	char		*map;
	t_params	*par;

	if (!(map = ft_read_file(file_name)))
		return (ft_display_error());
	if (!(par = (t_params *)malloc(sizeof(t_params))))
		return (0);
	if (!is_valid(par, map))
		return (ft_display_error());
	else
	{
		par->max = 0;
		par->max_i = 0;
		par->max_j = 0;
		if (!parse_map(par))
			return (0);
		display_bsq(par);
	}
	return (1);
}

int		ft_display_standard(void)
{
	char		buf[BUF_SIZE + 1];
	int			r;
	char		*map;
	t_params	*par;

	if (!(map = (char *)malloc(sizeof(char))))
		return (0);
	map[0] = '\0';
	while ((r = read(0, buf, BUF_SIZE)))
	{
		buf[r] = '\0';
		map = ft_strjoin(map, buf);
	}
	if (!(par = (t_params *)malloc(sizeof(t_params))) || !is_valid(par, map))
		return (ft_display_error());
	else
	{
		par->max = 0;
		par->max_i = 0;
		par->max_j = 0;
		if (!parse_map(par))
			return (0);
		display_bsq(par);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int			i;

	if (ac == 1)
		ft_display_standard();
	else
	{
		i = 1;
		while (i < ac)
		{
			start_bsq(av[i++]);
			if (i != ac)
				ft_putstr("\n");
		}
	}
	return (0);
}
