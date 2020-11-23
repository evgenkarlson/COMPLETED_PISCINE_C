/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyusuf-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:52:57 by fyusuf-a          #+#    #+#             */
/*   Updated: 2019/08/20 15:48:59 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define SIZE_1B 1
# define SIZE_3M 3000000

# define SIZE_MAP 100

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "utilities.h"
# include "ft_bool.h"

typedef struct	s_grid {
	UINT			w;
	UINT			h;
	char			*source;
	unsigned char	**map;
	unsigned char	translate[3];
}				t_grid;

typedef struct	s_solution {
	UINT	size;
	UINT	x;
	UINT	y;
}				t_solution;

typedef	enum {
	empty,
	obstacle,
	fill,
}	t_block;

t_bool			ft_load_grid(char *path, t_grid *grid);
void			ft_free_grid(t_grid *grid);
void			ft_process_grid(t_grid *grid, t_solution *sol);

t_bool			ft_parse_header_line(t_grid *grid, char *line, UINT length);
t_bool			ft_parse_normal_line(t_grid *grid, char *line, UINT length);
t_bool			ft_read_full(int fd, char **file_content, UINT *total);
t_bool			ft_has_width_changed(t_grid *grid, UINT *curr_w);
t_bool			ft_process_lines(t_grid *grid, UINT index,
							char *file_content, UINT total);
t_bool			ft_parse_grid(int fd, t_grid *grid);

t_bool			find_solution(t_solution *sol, const t_grid *grid);

void			ft_print_solution(t_grid *grid, t_solution *solution);

#endif
