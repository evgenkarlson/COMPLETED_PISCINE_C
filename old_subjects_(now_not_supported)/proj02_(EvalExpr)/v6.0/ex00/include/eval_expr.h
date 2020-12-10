/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 09:11:27 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/22 09:11:32 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

typedef enum	e_op
{
	OP_ADD = '+',
	OP_SUB = '-',
	OP_MUL = '*',
	OP_DIV = '/',
	OP_MOD = '%'
}				t_op;

typedef enum	e_priority
{
	PRIMARY = 0,
	UNARY = 1,
	MULTIPLICATIVE = 2,
	ADDITIVE = 3
}				t_priority;

int				eval_expr(char *str);
void			ft_putnbr(int nbr);
void			ft_putchar(char c);

#endif
