/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 10:38:43 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/02/12 20:52:12 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPERS_H

# define FT_HELPERS_H

int		get_max_size(int **grid, int col, int row, int size, int xmax, int ymax);

int		find_max(int **final, int *row, int *col, int x, int y);

char	get_char(char *map, int y, int pos);

int		find_y(char *map);

int		find_x(char *map);

#endif
