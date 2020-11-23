/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 23:16:14 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/23 23:16:29 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_number(char c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int		is_operator(char c)
{
	if (c == '%' || c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	else
		return (0);
}

int		get_precedence(char c)
{
	if (c == '*' || c == '/' || c == '%')
		return (2);
	else
		return (1);
}

char	*getnextelement(char *str)
{
	int		i;
	int		j;
	char	*num;

	i = 0;
	if (is_number(str[i]) || (str[i] == '-' && is_number(str[i + 1])))
	{
		j = i + 1;
		while (is_number(str[j]))
			j++;
		num = (char*)malloc(sizeof(char) * (j + 1));
		return (ft_strncpy(num, str, (unsigned int)(j)));
	}
	else
		return (str);
}
