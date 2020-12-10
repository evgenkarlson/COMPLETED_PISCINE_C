/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/12/06 22:59:14 by evgenkarlson     ###   ########.fr       */
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


#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, \
							int (*cmpf)(void *, void *))
{
	if (*root == ((void *)0))
		*root = btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}


/* ************************************************************************** */
/* ************************************************************************** */

void	btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *))
{
	if (!(*root))
		*root = btree_create_node(item);
	else if (cmpf(item, (*root)->item) >= 0)
		btree_insert_data(&(*root)->right, item, cmpf);
	else
		btree_insert_data(&(*root)->left, item, cmpf);
}

/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_btree.h"

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
/* ************************************************************************** */
