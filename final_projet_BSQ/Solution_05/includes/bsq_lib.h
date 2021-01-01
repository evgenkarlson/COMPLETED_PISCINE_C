/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 09:15:10 by etaranti          #+#    #+#             */
/*   Updated: 2020/11/11 20:49:01 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_LIB_H
# define BSQ_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	g_full;
char	g_obst;
char	g_empty;
int		g_row;
int		**g_board;

int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_rowlen(char *str, int fd);
int		ft_strerror(void);
int		ft_setok(void);
int		ft_lsrow(int fd, char *file);
int		ft_fullboard(int len, int fd);
void	ft_printboard(int len);
int		ft_charsafe(char c, int *col, int len, int *row);
void	ft_findsquare(int col);
void	ft_spcase(int *max, int col);
int		ft_checklen(int *j, int len, int *i);

#endif
