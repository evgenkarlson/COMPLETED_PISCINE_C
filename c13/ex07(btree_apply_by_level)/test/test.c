/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/12/25 22:19:48 by evgenkarlson     ###   ########.fr       */
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

void	btree_process_level(t_btree *root, int *t, int level,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (root)
	{
		if (level == 1)
		{
			applyf(root->item, t[0], t[1]);
			t[1] = 0;
		}
		else if (level > 1)
		{
			btree_process_level(root->left, t, level - 1, applyf);
			btree_process_level(root->right, t, level - 1, applyf);
		}
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
							int current_level, int is_first_elem))
{
	int t[2];
	int coun_lvl;
	int i;

	if (root)
	{
		coun_lvl = btree_level_count(root);
		i = 0;
		while (i < coun_lvl)
		{
			t[0] = i;
			t[1] = 1;
			btree_process_level(root, t, ++i, applyf);
		}
	}
}

void	test_btree_level(void *item, int current_level, int is_first_elem)
{
	if (item)
	{
		ft_putstr("Current node:\t\t\t\t\" ");
		ft_putstr((char *)item);
		ft_putstr(" \" \nThe level at which it is located:\t\" ");
		ft_putchar((current_level / 10) + '0');
		ft_putchar((current_level % 10) + '0');
		ft_putstr(" \"\nIs he the first on this level:\t\t");
		if (is_first_elem)
			ft_putstr("\" yes \"");
		else
			ft_putstr("\" no \"");
	ft_putstr("\n---------------------------------------------------------------\n");
	}
}

/* ************************************************************************** */


int 	main(void)
{
	t_btree		*tree_temp;

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
	ft_putstr("|              test \'btree apply by level\'                    |\n");
	ft_putstr(" -------------------------------------------------------------\n\n");
	
	btree_apply_by_level(tree_temp, test_btree_level);
	ft_putchar('\n');
	
	return (0);
}