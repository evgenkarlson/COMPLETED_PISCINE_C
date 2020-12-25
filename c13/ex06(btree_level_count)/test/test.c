/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/12/21 22:48:03 by evgenkarlson     ###   ########.fr       */
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

/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

/* ************************************************************************** */

void	btree_apply_infix_mod(t_btree *root, void (*applyf)(void *), unsigned int i)
{
	if (root)
	{
		unsigned int j;

		j = i;
		if (root->left)
			btree_apply_infix_mod(root->left, applyf, (i + 1));
		while (j--)
		{
			ft_putchar('\t');
		}
		(*applyf)(root->item);
		ft_putchar('\n');
		ft_putchar('\n');
		if (root->right)
			btree_apply_infix_mod(root->right, applyf, (i + 1));
	}
}


/* ************************************************************************** */

t_btree	*btree_create_node(void *item)
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


void	btree_insert_data(t_btree **root, void *item, \
							int (*cmpf)(void *, void *))
{	
	if (!(*root))

		*root = btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}


/* ************************************************************************** */

int		btree_level_count(t_btree *root)
{
	if (root)
		return (1 + MAX(btree_level_count(root->left), \
				btree_level_count(root->right)));
	return (0);
}

/* ************************************************************************** */

int 	main(void)
{
	t_btree		*tree_temp;
	int 		levels;
	
	tree_temp = btree_create_node("root");
	tree_temp->left = btree_create_node("one children");
	tree_temp->right = btree_create_node("two children");

	tree_temp->left->left = btree_create_node("one grand-children from one children");
	tree_temp->left->right = btree_create_node("two grand-children from one children");
	
	tree_temp->right->left = btree_create_node("one grand-children from two children");
	tree_temp->right->right = btree_create_node("two grand-children from two children");
	
	ft_putstr(" ------------------------------------------------------------\n");
	ft_putstr("|                       map of tree                          |\n");
	ft_putstr(" ------------------------------------------------------------\n\n");
	btree_apply_infix_mod(tree_temp, (void *)&ft_putstr, 1);
	ft_putstr("\n\n");

	ft_putstr(" -------------------------------------------------------------\n");
	ft_putstr("|                   btree level count                         |\n");
	ft_putstr(" -------------------------------------------------------------\n\n");
	if ((levels = btree_level_count(tree_temp)))
	{
		ft_putstr("    Success: the btree have a maximum depth of \"");
		ft_putchar((levels / 10) + '0');
		ft_putchar((levels % 10) + '0');
		ft_putstr("\" levels!\n\n");
	}
	else
	{
		ft_putstr("\t\tFail: btree is empty!\n\n");
	}
	
	return (0);
}


/* ************************************************************************** */
