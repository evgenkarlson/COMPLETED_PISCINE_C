/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 06:26:48 by jaleman           #+#    #+#             */
/*   Updated: 2017/03/27 06:26:49 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : brackets
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of strings in arguments. For each
argument, the program prints on the standard output "OK" followed by a newline
if the expression is correctly bracketed, otherwise it prints "Error" followed by
a newline.

Symbols considered as 'brackets' are brackets '(' and ')', square brackets '['
and ']'and braces '{' and '}'. Every other symbols are simply ignored.

An opening bracket must always be closed by the good closing bracket in the
correct order. A string which not contains any bracket is considered as a
correctly bracketed string.

If there is no arguments, the program must print only a newline.

Examples :

$> ./brackets '(johndoe)' | cat -e
OK$
$> ./brackets '([)]' | cat -e
Error$
$> ./brackets '' '{[(0 + 0)(1 + 1)](3*(-1)){()}}' | cat -e
OK$
OK$
$> ./brackets | cat -e
$
$>


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>
#define BUFF_SIZE (4096)

static int	match_brackets(char a, char b)
{
	return ((a == '[' && b == ']') || (a == '{' && b == '}') \
				|| (a == '(' && b == ')'));
}

static int	check_brackets(char *str)
{
	int		i;
	int		top;
	int		stack[BUFF_SIZE];

	i = 0;
	top = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			stack[++top] = str[i];
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			if (!match_brackets(stack[top--], str[i]))
				return (0);
		i += 1;
	}
	return (!top);
}

int			main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc == 1)
		write(1, "\n", 1);
	while (--argc)
	{
		if (check_brackets(argv[++i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
