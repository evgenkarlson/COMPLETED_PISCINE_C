/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforciol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:33:55 by pforciol          #+#    #+#             */
/*   Updated: 2018/07/25 18:50:11 by ple-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map_params
{
	int		lines;
	int		columns;
	int		size;
	char	empty;
	char	obstacles;
	char	fill;
}				t_map_params;

typedef struct	s_map_loc
{
	int x;
	int y;
	int point;
}				t_map_loc;

#endif
