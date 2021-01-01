/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:24:26 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/21 20:10:34 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "utilities.h"

t_bool	ft_parse_header_line(t_grid *grid, char *line, UINT length)
{
	t_bool	result;

	if (length < 4)
		return (false);
	grid->translate[fill] = line[length - 1];
	grid->translate[obstacle] = line[length - 2];
	grid->translate[empty] = line[length - 3];
	result = ft_atoi_n_strict(line, length - 3, &(grid->h));
	return (result);
}

t_bool	ft_parse_normal_line(t_grid *grid, char *line, UINT length)
{
	UINT	index;
	char	current;

	if (length < 1)
		return (false);
	grid->w = length;
	index = 0;
	while (index < length)
	{
		current = line[index];
		if (current != grid->translate[empty]
				&& current != grid->translate[obstacle]
				&& current != grid->translate[fill])
			return (false);
		index++;
	}
	return (true);
}

t_bool	ft_has_width_changed(t_grid *grid, UINT *curr_w)
{
	if (*curr_w == (UINT)-1)
		*curr_w = grid->w;
	return (*curr_w != grid->w);
}

t_bool	ft_process_lines(t_grid *grid, UINT index,
							char *file_content, UINT total)
{
	UINT	jndex;
	UINT	y;
	UINT	curr_w;

	y = 0;
	curr_w = -1;
	while (index < total && y < grid->h)
	{
		jndex = index;
		while (file_content[jndex] != '\n')
			if (jndex++ + 1 >= total)
				return (false);
		if (ft_parse_normal_line(grid, file_content + index, jndex - index))
		{
			grid->map[y++] = (UCHR *)(file_content + index);
			if (ft_has_width_changed(grid, &curr_w))
				return (false);
		}
		else
			return (false);
		index = jndex + 1;
	}
	return (y == grid->h);
}

t_bool	ft_parse_grid(int fd, t_grid *grid)
{
	char	*file_content;
	UINT	total;
	UINT	index;

	grid->map = 0;
	if (!ft_read_full(fd, &file_content, &total))
		return (false);
	grid->source = file_content;
	index = 0;
	while (index < total)
	{
		if (file_content[index] == '\n')
		{
			if (!ft_parse_header_line(grid, file_content, index))
				return (false);
			if (!(grid->map = malloc(sizeof(char *) * grid->h)))
				return (false);
			return (ft_process_lines(grid, index + 1, file_content, total));
		}
		index++;
	}
	return (false);
}
