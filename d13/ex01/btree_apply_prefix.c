/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/29 18:53:54 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/30 17:19:34 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		(*applyf)(root->item);
		if (root->left)
			btree_apply_prefix(root->left, applyf);
		if (root->right)
			btree_apply_prefix(root->right, applyf);
	}
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	(*applyf)(root->item);
	if (root->left != 0)
		btree_apply_prefix(root->left, (applyf));
	if (root->right != 0)
		btree_apply_prefix(root->right, (applyf));
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	(*applyf)(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
