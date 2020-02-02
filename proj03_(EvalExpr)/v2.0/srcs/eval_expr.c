/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 22:16:31 by adespond          #+#    #+#             */
/*   Updated: 2015/09/20 22:57:08 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval.h"

int		eval_expr(char *str)
{
	t_btree		*root;
	int			resultat;

	resultat = 0;
	str = ft_trim_space(str);
	root = btree_create_node(str);
	parse(root);
	resultat = calculate_parse(root);
	return (resultat);
}
