/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/29 21:57:46 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/30 17:21:25 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		if (root->left)
			btree_apply_suffix(root->left, applyf);
		if (root->right)
			btree_apply_suffix(root->right, applyf);
		(*applyf)(root->item);
	}
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root->left != 0)
		btree_apply_suffix(root->left, (*applyf));
	if (root->right != 0)
		btree_apply_suffix(root->right, (*applyf));
	(*applyf)(root->item);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	(*applyf)(root->item);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
