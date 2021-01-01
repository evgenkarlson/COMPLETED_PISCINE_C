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

#ifndef FT_MAP_H

# define FT_MAP_H

# define BUFFSIZE 4097

void	print_map(int **final, char *map);

int		**find_square(int **grid, int x, int y);

int		*convert_row(char *row, int x, char empty, char obstacle);

char	**split_rows(char *map, int x, int y);

int		**build_grid(int **grid, char *map, int x, int y);

#endif
