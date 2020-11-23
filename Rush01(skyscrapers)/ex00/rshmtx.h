/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rshmtx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/23 12:10:01 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSHMTX_H
# define RSHMTX_H

int		**create_mtx(int value, int row, int col);
int		***ft_poss_val_ini(int ***possible_val);
void	ft_zeros_cell(int **mtx, int r, int c);
void	ft_zeros_3arr(int ***cube, int layer, int row, int col);

#endif
