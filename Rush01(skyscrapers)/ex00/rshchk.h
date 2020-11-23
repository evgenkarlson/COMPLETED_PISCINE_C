/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rshchk.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/23 12:09:37 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSHCHK_H
# define RSHCHK_H

void	ft_cluescheck(char *clues_str, int *clues_int);
void	ft_cluestomtx(int *clues_arr, int **clues_mtx);
int		***ft_checks(int **clues_mtx, int ***cube);

#endif
