/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:54:17 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 19:33:59 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>

typedef unsigned short	t_uns;
typedef unsigned char	t_unc;

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_mapcfg
{
	t_uns	x;
	t_uns	y;
	t_unc	char_empty;
	t_unc	char_mine;
	t_unc	char_square;
}				t_mapcfg;

typedef struct	s_square
{
	t_uns	x;
	t_uns	y;
	t_uns	size;
}				t_square;

void	ft_stdin(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
void	ft_destroy(void **array);
void	ft_put_map(t_unc **map_char);
void	ft_paint_over_the_squar(t_unc **map_char, t_mapcfg *grid_cfg, \
								t_square *final_result);
void	ft_find_coord_nearest_squar(t_uns **map_num, t_mapcfg *grid_cfg, \
									t_square *final_result);
t_uns	**ft_conv_char_arr_to_num(t_unc **map_char, t_mapcfg *grid_cfg);
t_unc	**ft_save_fmap_to_arr(char *file_map, t_mapcfg *grid_cfg);
t_bool	ft_cfg_and_check(char *file_map, t_mapcfg *grid_cfg);
void	bsq(char *file_map);

#endif
