/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <adespond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 00:52:30 by adespond          #+#    #+#             */
/*   Updated: 2015/09/16 05:31:16 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_OP_H
# define __FT_OP_H
# include <unistd.h>

typedef struct	s_cal
{
	char	op;
	int		(*f)(int a, int b);
}				t_cal;
int				ft_atoi(char *str);
int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_mod(int a, int b);
int				ft_div(int a, int b);
int				ft_do_op(int a, char op, int b);
void			ft_putchar(char c);
void			ft_putnbr(int nbr);
void			ft_putstr(char *str);
#endif
