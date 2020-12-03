/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/12/03 17:53:01 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex04/
**  Файлы для сдачи: btree_insert_data.c,.c, ft_btree.h	
**  Разрешенные функции: btree_create_node
**
** ************************************************************************** **
**
** 
**	• Создайте функцию 'btree_insert_data', которая вставляет элемент "item" в
**  дерево. Дерево, переданное в качестве аргумента, будет отсортировано: для
**  каждого узла все нижние элементы расположены слева, а все более высокие 
**  или равные элементы - справа. Мы также передадим в качестве аргумента 
**  функцию сравнения, аналогичную 'strcmp'.
** 
** 
**	• Параметр 'root' указывает на корневой узел дерева. При первом вызове он 
**  должен указывать на 'NULL' (нулевой указатель).
** 
** 
**	• Вот как эта функция должна быть объявлена:
**
**	void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
** 
** 
** ************************************************************************** */
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

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

/* ************************************************************************** */

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		(*applyf)(root->item);
		if (root->left)
			btree_apply_prefix(root->left, applyf);
		if (root->right)
			btree_apply_prefix(root->right, applyf);
	}
	ft_putstr("\n");
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
	t_btree	*node;

	if (!(*root))
	{
		*root = btree_create_node(item);
	}
	else
	{
		node = *root;
		if ((*cmpf)(item, node->item) < 0)
		{
			if (node->left)
				btree_insert_data(&node->left, item, cmpf);
			else
				node->left = btree_create_node(item);
		}
		else
		{
			if (node->right)
				btree_insert_data(&node->right, item, cmpf);
			else
				node->right = btree_create_node(item);
		}
	}
}


/* ************************************************************************** */

int 	main(void)
{
	t_btree 	*root;
	t_btree		*tree_temp;

	tree_temp = btree_create_node("root \n");
	tree_temp->left = btree_create_node("\t one children  \n");
	tree_temp->right = btree_create_node("\t two children \n");

	tree_temp->left->left = btree_create_node("\t\t\t one grand-children from one children \n");
	tree_temp->left->right = btree_create_node("\t\t\t two grand-children from one children \n");
	
	tree_temp->right->left = btree_create_node("\t\t\t one grand-children from two children \n");
	tree_temp->right->right = btree_create_node("\t\t\t two grand-children from two children \n");

	root = ((void *)0);
	btree_insert_data(&root, "05", (void *)&ft_strcmp);
	btree_insert_data(&root, "03", (void *)&ft_strcmp);
	btree_insert_data(&root, "08", (void *)&ft_strcmp);
	btree_insert_data(&root, "04", (void *)&ft_strcmp);
	btree_insert_data(&root, "01", (void *)&ft_strcmp);
	btree_insert_data(&root, "09", (void *)&ft_strcmp);
	btree_insert_data(&root, "00", (void *)&ft_strcmp);
	btree_insert_data(&root, "07", (void *)&ft_strcmp);
	btree_insert_data(&root, "06", (void *)&ft_strcmp);
	btree_insert_data(&root, "02", (void *)&ft_strcmp);
	btree_insert_data(&root, "04", (void *)&ft_strcmp);
	btree_insert_data(&root, "07", (void *)&ft_strcmp);
	ft_putstr(("<"));
	btree_apply_prefix(root, (void *)&ft_putstr);
	ft_putstr("\n>538419076247\n");
/*
	ft_putstr("<");
	btree_apply_infix(root, (void *)&ft_putstr);
	ft_putstr("\n>012344567789\n");
	ft_putstr("<");
	btree_apply_suffix(root, (void *)&ft_putstr);
	ft_putstr("\n>021443677985\n");
*/
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */
