/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuntingyard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 23:04:27 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/23 23:39:02 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clearremainder(void)
{
	while (g_opstack.top != -1)
		if (g_opstack.stk[g_opstack.top] == '(')
			pop();
		else
			queue_insert(pop());
	queue_insert("e");
}

int		precedencechecker(char *nextelement)
{
	if ((g_opstack.top != -1) &&
			(get_precedence(g_opstack.stk[g_opstack.top])
			>= get_precedence(nextelement[0]))
			&& (g_opstack.stk[g_opstack.top] != '('))
		return (1);
	else
		return (0);
}

void	handleoperators(char *nextelement)
{
	if (is_operator(nextelement[0]))
	{
		while (precedencechecker(nextelement))
			queue_insert(pop());
		push(nextelement[0]);
	}
	else if (nextelement[0] == '(')
		push(nextelement[0]);
	else if (nextelement[0] == ')')
	{
		while (g_opstack.stk[g_opstack.top] != '(')
			queue_insert(pop());
		pop();
	}
}

void	*shunting_yard(char *str)
{
	int		i;
	char	*nextelement;

	nextelement = (char*)malloc(sizeof(char) * 50);
	i = 0;
	while (*str != '\0')
	{
		while (str[0] == ' ')
			str++;
		nextelement = getnextelement(str);
		if (is_number(nextelement[0]) || (str[0] == '-' && is_number(str[1])))
		{
			queue_insert(nextelement);
			while (is_number(str[1]) && (str[1] != '\0'))
				str++;
		}
		else
			handleoperators(nextelement);
		str++;
	}
	clearremainder();
	return (0);
}
