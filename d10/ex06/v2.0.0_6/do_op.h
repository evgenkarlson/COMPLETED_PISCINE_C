/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 01:47:05 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/24 14:57:12 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H
# include <unistd.h>

int		sum(int a, int b);
int		subtract(int a, int b);
int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		ft_atoi(char *str);
int		(*g_p[5]) (int x, int y);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);

int		g_div;
int		g_mod;

#endif
