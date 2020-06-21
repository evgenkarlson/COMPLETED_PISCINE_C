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

int		sum(int a, int b, int *error);
int		subtract(int a, int b, int *error);
int		mul(int a, int b, int *error);
int		div(int a, int b, int *error);
int		mod(int a, int b, int *error);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int     ft_getop(char *c);
void    ft_do_op(int argc, char *argv[]);


#endif