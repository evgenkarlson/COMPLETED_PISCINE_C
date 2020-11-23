/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/19 17:54:19 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_btree.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

/* ************************************************************************** */

t_btree		*btree_create_node(void *item)
{
	t_btree		*tree;

	if ((tree = (t_btree *)malloc(sizeof(t_btree))))
	{
		tree->left = ((void *)0);
		tree->right = ((void *)0);
		tree->item = item;
	}
	return (tree);
}

/* ************************************************************************** */

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		if (root->left)
			btree_apply_suffix(root->left, applyf);
		if (root->right)
			btree_apply_suffix(root->right, applyf);
		(*applyf)(root->item);
	}
}

int			main(void)
{
	t_btree		*tree_temp;

	tree_temp = btree_create_node("root \n");
	tree_temp->left = btree_create_node("\t one children  \n");
	tree_temp->right = btree_create_node("\t two children \n");

	tree_temp->left->left = btree_create_node("\t\t\t one grand-children from one children \n");
	tree_temp->left->right = btree_create_node("\t\t\t two grand-children from one children \n");
	
	tree_temp->right->left = btree_create_node("\t\t\t one grand-children from two children \n");
	tree_temp->right->right = btree_create_node("\t\t\t two grand-children from two children \n");
	
	btree_apply_suffix(tree_temp, (void *)&ft_putstr);
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
