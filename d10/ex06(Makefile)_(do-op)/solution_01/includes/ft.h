/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_OP_H
# define __FT_OP_H
# include <unistd.h>

typedef struct	s_cal
{
	char	op;
	int		(*ft)(int a, int b);
}				t_cal;

int				ft_sum(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_mod(int a, int b);
int				ft_div(int a, int b);
int				check(char op, int b);
int				ft_calc(int x, char operator, int y);
void			ft_do_op(int argc, char *argv[]);
int				ft_atoi(char *str);
void			ft_putnbr(int nbr);
void			ft_putchar(char c);
void			ft_putstr(char *str);

#endif