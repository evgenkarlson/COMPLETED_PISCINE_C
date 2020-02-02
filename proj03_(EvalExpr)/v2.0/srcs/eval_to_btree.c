/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_to_btree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 21:51:25 by adespond          #+#    #+#             */
/*   Updated: 2015/09/20 22:59:25 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval.h"

char	*ft_get_first(char *str, int i)
{
	char	*ret;
	int		j;

	j = 0;
	ret = (char *)malloc(i + 1);
	while (j < i)
	{
		ret[j] = str[j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_get_last(char *str, int i)
{
	int		length;
	char	*ret;

	length = 0;
	while (str[i + 1 + length] != '\0')
		length++;
	ret = (char *)malloc(length + 1);
	length = 0;
	while (str[i + 1 + length] != '\0')
	{
		ret[length] = str[i + 1 + length];
		length++;
	}
	ret[length] = '\0';
	return (ret);
}

char	*ft_get_op(char *str, int i)
{
	char	*op;

	op = (char *)malloc(2);
	op[0] = str[i];
	op[1] = '\0';
	return (op);
}

char	*remove_par(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i - 1] = '\0';
	return (&str[1]);
}

char	*check_par(char *str)
{
	int i;
	int par;

	par = 0;
	i = 0;
	if (str[0] == '(')
	{
		while (str[i + 1] != '\0')
		{
			if (str[i] == '(')
				par++;
			if (str[i] == ')')
				par--;
			if (par == 0)
				return (str);
			i++;
		}
		return (remove_par(str));
	}
	return (str);
}
