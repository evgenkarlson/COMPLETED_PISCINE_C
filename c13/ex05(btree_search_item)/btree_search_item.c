/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/12/11 01:05:01 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex05/
**  Файлы для сдачи: btree_search_item.c, ft_btree.h	
**  Разрешенные функции: Никакие
**
** ************************************************************************** **
**
** 
**	• Создайте функцию 'btree_search_item', которая возвращает первый элемент, 
**  связанный со справочными данными, указанными в качестве аргумента. Дерево 
**  следует просматривать, используя инфиксный обход. Если элемент не найден, 
**  функция должна вернуть 'NULL'.
** 
** 
**	• Вот как эта функция должна быть объявлена:
**
**	void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
** 
** 
** ************************************************************************** */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
							int (*cmpf)(void *, void *))
{
	void	*out;

	out = ((void *)0);
	if (root)
	{
		out = btree_search_item(root->left, data_ref, cmpf);
		if (!out && !((*cmpf)(root->item, data_ref)))
			out = root->item;
		if (!out)
			out = btree_search_item(root->right, data_ref, cmpf);
	}
	return (out);
}



/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	void	*result;

	result = ((void *)0);
	if (root->left)
		result = btree_search_item(root->left, data_ref, cmpf);
	if (!result && cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (!result && root->right)
		result = btree_search_item(root->right, data_ref, cmpf);
	return (result);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	if (!root || !data_ref)
		return (0);
	if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	if (root->left)
		return (btree_search_item(root->left, data_ref, cmpf));
	if (root->right)
		return (btree_search_item(root->right, data_ref, cmpf));
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void *item;

	if (!root)
		return ((void *)0);
	if ((item = btree_search_item(root->left, data_ref, cmpf)))
		return (item);
	if (!cmpf(data_ref, root->item))
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}


/* ************************************************************************** */
/* ************************************************************************** */



#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	t_btree *res;

	res = 0;
	if (root)
	{
		res = btree_search_item(root->left, data_ref, cmpf);
		if (res)
			return (res);
		if (cmpf(root->item, data_ref) == 0)
			return (root);
		res = btree_search_item(root->right, data_ref, cmpf);
		if (res)
			return (res);
	}
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *d, int (*cmpf)(void *, void *))
{
	int cmp;

	if (root == ((void *)0) || cmpf == ((void *)0))
		return ((void *)0);
	if ((cmp = cmpf(root->item, d)) == 0)
		return (root->item);
	if (cmp > 0)
		return (btree_search_item(root->left, d, cmpf));
	return (btree_search_item(root->right, d, cmpf));
}