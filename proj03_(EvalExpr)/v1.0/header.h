/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 22:49:53 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/23 23:21:54 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int				eval_expr(char *str);
void			*shunting_yard(char *str);
char			*read_rpn(char *str);
void			ft_putchar(char c);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
void			ft_putnbr(int nb);
void			push(char n);
char			*pop(void);
void			queue_insert(char *n);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
void			rpush(int n);
int				rpop(void);
int				calc_result(char **arr);
int				do_operation(int x, int y, char op);
int				is_number(char c);
int				is_operator(char c);
int				get_precedence(char c);
char			*getnextelement(char *str);

char			*g_queue_array[9999];

typedef struct	s_stack
{
	char	stk[9999];
	int		top;
}				t_stack;

t_stack		g_opstack;

typedef struct	s_rstack
{
	int stk[9999];
	int top;
}				t_rstack;

t_rstack		g_rstack;

#endif
