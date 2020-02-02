/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_do_op.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 01:47:05 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/25 14:46:51 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADVANCED_DO_OP_H
# define FT_ADVANCED_DO_OP_H
# include <unistd.h>

int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
int				ft_usage(int a, int b);
int				ft_atoi(char *str);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
int				g_div;
int				g_mod;
int				g_val;

typedef struct	s_opp {
	char		*c;
	int			(*f)(int a, int b);
}				t_opp;

#endif
