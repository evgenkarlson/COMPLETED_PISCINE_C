/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 22:00:25 by adespond          #+#    #+#             */
/*   Updated: 2015/09/20 23:07:16 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval.h"

void	create_node(char *str, int i, t_btree *node)
{
	node->left = btree_create_node(ft_get_first(str, i));
	node->right = btree_create_node(ft_get_last(str, i));
	node->value = ft_get_op(str, i);
	parse(node->left);
	parse(node->right);
}

int		find_plus_minus(char *str, t_btree *node)
{
	int i;
	int par;

	par = 0;
	i = ft_strlen(str) - 1;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			par++;
		if (str[i] == ')')
			par--;
		if ((str[i] == '+' || str[i] == '-') && par == 0)
		{
			create_node(str, i, node);
			return (1);
		}
		i--;
	}
	return (0);
}

int		find_mult_div(char *str, t_btree *node)
{
	int i;
	int par;

	i = ft_strlen(str) - 1;
	par = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			par++;
		if (str[i] == ')')
			par--;
		if ((str[i] == '*' || str[i] == '/' || str[i] == '%') && par == 0)
		{
			create_node(str, i, node);
			return (1);
		}
		i--;
	}
	return (0);
}

void	parse(t_btree *node)
{
	int		i;
	char	*str;
	int		stop;
	int		par;

	stop = 0;
	par = 0;
	if (node->value)
	{
		str = check_par(node->value);
		i = ft_strlen(str) - 1;
		if (find_plus_minus(str, node) == 1)
			return ;
		if (find_mult_div(node->value, node) == 1)
			return ;
	}
}
