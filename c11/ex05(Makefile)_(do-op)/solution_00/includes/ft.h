/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DO_OP_H
# define DO_OP_H
# include <unistd.h>

int		ft_sum(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_get_op(char c);
int		ft_calc(int x, char operator, int y);
void    ft_do_op(int argc, char *argv[]);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);


#endif