/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 17:39:54 by adespond          #+#    #+#             */
/*   Updated: 2015/09/20 17:32:42 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLLE_H
# define FT_COLLE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*colle00_0(int x, int y);
char	*colle00_1(int x, int y);
char	*colle00_2(int x, int y);
char	*colle00_3(int x, int y);
char	*colle00_4(int x, int y);
char	*generate_line(int x, char *colle, char *pattern, int line);
char	*generate_colle(int x, int y, char *pattern);
int		ft_strcmp(char *s1, char *s2);
int		ft_put_is_colle(char *colle, int x, int y, int first);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_atoi(char *str);
void	read_pipe();
void	cmp_colle(int x, int y, char *save);
int		ft_str_is_numeric(char *str);
#endif
