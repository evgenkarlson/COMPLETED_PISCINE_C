/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 00:37:31 by adespond          #+#    #+#             */
/*   Updated: 2015/09/20 22:46:40 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval.h"

t_btree		*btree_create_node(void *value)
{
	t_btree	*tree;

	tree = (t_btree*)malloc(sizeof(t_btree));
	if (tree)
	{
		tree->left = 0;
		tree->right = 0;
		tree->value = value;
	}
	return (tree);
}
