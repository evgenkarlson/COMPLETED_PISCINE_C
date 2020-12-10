/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:50:11 by flklein           #+#    #+#             */
/*   Updated: 2018/09/09 18:24:56 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
int		**create_tab(char **av);
void	copy_tab(int **tab, int **old);
void	print_tab(int **tab);
int		test(int **tab, int l, int c, int nb);
int		is_valid(int **tab);

#endif
