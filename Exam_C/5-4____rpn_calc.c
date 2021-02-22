/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-4____rpn_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/02/11 21:49:49 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **

Assignment name  : rpn_calc
Expected files   : *.c, *.h 
Allowed functions: atoi, printf, write, malloc, free
--------------------------------------------------------------------------------

Напишите программу, которая принимает в качестве первого аргумента строку, 
содержащую уравнение, записанное в Обратной Польской нотации (RPN), далее 
вычисляет уравнение и печатает результат в стандартном выводе, за которым 
следует новая строка.

Обратная Польская запись - это математическая запись, в которой каждый 
оператор следует за всеми своими операндами. В 'RPN' каждый встреченный 
оператор оценивает предыдущие 2 операнда, и затем результат этой операции 
становится первым из двух операндов для последующего оператора. Операнды 
и операторы должны быть разделены хотя бы одним пробелом.

Вы должны реализовать следующие операторы: "+", "-", "*", "/", и "%".

Если строка недействительна или нет ровно одного аргумента, вы должны 
вывести «Error» в стандартный вывод, за которым будет следовать новая 
строка.

Все указанные операнды должны уместиться в "int".



Примеры формул, преобразованных в RPN:

3 + 4                   >>    3 4 +
((1 * 2) * 3) - 4       >>    1 2 * 3 * 4 -  ou  3 1 2 * * 4 -
50 * (5 - (10 / 9))     >>    5 10 9 / - 50 *



Вот как вычислить формулу в RPN:

1 2 * 3 * 4 -
2 3 * 4 -
6 4 -
2

Or:

3 1 2 * * 4 -
3 2 * 4 -
6 4 -
2

Пример:

$> ./rpn_calc "1 2 * 3 * 4 +" | cat -e
10$
$> ./rpn_calc "1 2 3 4 +" | cat -e
Error$
$> ./rpn_calc |cat -e
Error$


** ************************************************************************** */
/* ************************************************************************** */


#include "ft_list.h"

/* 'ft_list.h' contains:

#ifndef RPN_CALC_H
# define RPN_CALC_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_s
{
	int			i;
	struct s_s	*next;
}				t_s;

int		check_input(char *s);

void	rpn_calc(char *s);
void	push(t_s **stack, int i);
int		pop(t_s **stack);
int		do_op(int i, int j, char o);

int		is_op(int c);
int		is_digit(int c);
int		is_space(int c);

#endif

*/

int	check_input(char *s)
{
	int	num_c;
	int	op_c;

	num_c = 0;
	op_c = 0;
	while (*s)
	{
		if (!(is_op(*s) || is_digit(*s) || is_space(*s)))
			return (0);
		if (is_op(*s))
		{
			if (num_c && (*(s - 1)) && !is_space(*(s - 1)))
					return (0);
			op_c++;
			if ((*s == '-' || *s == '+') && (*(s + 1)) &&
					is_digit(*(s + 1)))
				op_c--;
		}
		else if (is_digit(*s))
		{
			if (!num_c || (*(s - 1) && !is_digit(*(s - 1))))
				num_c++;
		}
		if (is_space(*s) && num_c <= op_c)
			return (0);
		++s;
	}
	return (num_c - op_c == 1 ? 1 : 0);
}

int	is_op(int c)
{
	return (c == '+' ||
			c == '-' ||
			c == '*' ||
			c == '/' ||
			c == '%');
}

int	is_digit(int c)
{
	return ('0' <= c && c <= '9');
}

int	is_space(int c)
{
	return (c == 32);
}

void	rpn_calc(char *s)
{
	t_s	**stack;
	int	num1;
	int	num2;

	if (stack = (t_s **)malloc(sizeof(t_s*)))
	{
		while (*s)
		{
			while (*s && is_space(*s))
				s++;
			if (*s && is_digit(*s))
			{
				push(stack, atoi(s));
				while (*s && is_digit(*s))
					s++;
			}
			else if (*s && is_op(*s))
			{
				if (*(s + 1) && is_digit(*(s + 1)))
				{
					push(stack, atoi(s));
					s++;
					while (is_digit(*s))
						s++;
				}
				else
				{
					num1 = pop(stack);
					num2 = pop(stack);
					if (num2 == 0 && (*s == '/' || *s == '%'))
					{
						printf("Error\n");
						return ;
					}
					push(stack, do_op(num1, num2, *s));
					s++;
				}
			}
		}
		printf("%i\n", (*stack)->i);
	}
}

void	push(t_s **stack, int i)
{
	t_s	*link;

	if (link = (t_s *)malloc(sizeof(t_s)))
	{
		link->i = i;
		if (*stack)
		{
			link->next = *stack;
			*stack = link;
		}
		else
		{
			link->next = *stack;
			stack = &link;
		}
	}
}

int		pop(t_s **stack)
{
	int	num;
	t_s *tmp;

	num = (*stack)->i;
	tmp = (*stack);
	*stack = (*stack)->next;
	free(tmp);
	return (num);
}

int	do_op(int i, int j, char c)
{
	if (c == '+')
		return (i + j);
	else if (c == '-')
		return (i - j);
	else if (c == '*')
		return (i * j);
	else if (c == '/')
		return (i / j);
	else if (c == '%')
		return (i % j);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2 && check_input(av[1]))
		rpn_calc(av[1]);
	else
		printf("Error\n");
	return (0);
}
