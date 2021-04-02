/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 05:38:47 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/03/10 01:51:39 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BSQ_H
# define __BSQ_H
# include <stdlib.h>
# include <unistd.h>
// # include <sys/types.h>
// # include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>

typedef unsigned short	t_uns;

typedef struct			s_grid
{
	unsigned short		x;
	unsigned short		y;
	unsigned char		char_empty;
	unsigned char		char_mine;
	unsigned char		char_square;
}						t_grid;

typedef struct			s_square
{
	struct s_coord		*start;
	short				length;
}						t_square;

typedef struct			s_coord
{
	unsigned short		x;
	unsigned short		y;
	struct s_coord		*next;
}						t_coord;

void					bsq(char *file);
t_uns					read_file(char *file);
t_uns					prepare_read(int fd);
t_uns					ft_read(int fd, char *buffer, t_grid *grid, t_coord *xy);
t_uns					ft_read_char(t_coord *xy, char *buffer, t_grid *grid, t_coord **begin);
t_grid					create_struct_grid();
t_uns					first_line(char *buffer, t_grid *grid);
short					check_bomb(t_uns *x, t_uns *y, t_uns l, t_coord **list);
t_square				*algo_bsq(t_coord **list, t_grid *grid);
t_coord					*create_mine(t_coord *xy);
void					push_back(t_coord **begin, t_coord *xy);
void					init_those(t_square **temp, t_square **max);
t_square				*square_init();
void					display(t_square *square, t_grid *grid, t_coord **begin);
t_uns					ft_after_read(t_coord *xy, t_grid *grid, t_coord **begin);

#endif
