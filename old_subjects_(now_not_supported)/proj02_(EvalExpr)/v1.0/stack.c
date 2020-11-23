/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 23:09:20 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/23 23:11:37 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push(char n)
{
	if ((g_opstack.top != (9999 - 1)))
	{
		g_opstack.top = g_opstack.top + 1;
		g_opstack.stk[g_opstack.top] = n;
	}
}

void	rpush(int n)
{
	if (g_rstack.top != (9999 - 1))
	{
		g_rstack.top = g_rstack.top + 1;
		g_rstack.stk[g_rstack.top] = n;
	}
}

char	*pop(void)
{
	char *num;

	num = (char*)malloc(sizeof(char) * 2);
	if (g_opstack.top == -1)
	{
		return (0);
	}
	else
	{
		num[0] = g_opstack.stk[g_opstack.top];
		num[1] = '\0';
		g_opstack.top = g_opstack.top - 1;
	}
	return (num);
}

int		rpop(void)
{
	int num;

	if (g_rstack.top == -1)
	{
		return (0);
	}
	else
	{
		num = g_rstack.stk[g_rstack.top];
		g_rstack.top = g_rstack.top - 1;
	}
	return (num);
}
