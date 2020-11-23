/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 10:26:46 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 15:02:27 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SUDOKU_H
# define __SUDOKU_H
# include <unistd.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		display(char **tab);
int			check_line(char **tab, char nb, int x);
int			check_column(char **tab, char nb, int y);
int			check_block(char **tab, int x, int y, char nb);
int			check_grille(char **tab, int n);
int			sudoku(char **tab, int position);
#endif
