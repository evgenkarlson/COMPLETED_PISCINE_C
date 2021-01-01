/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:46:12 by ple-thie          #+#    #+#             */
/*   Updated: 2018/07/25 22:05:46 by ple-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

char	*ft_read_file(int fd, t_map_params *params);
int		**ft_map_converter(char *grid, t_map_params *params);
int		**ft_square_calc(int **map, t_map_params map_params);

#endif
