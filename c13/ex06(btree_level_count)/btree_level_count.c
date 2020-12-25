/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/12/22 21:56:00 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex06/
**  Файлы для сдачи: btree_level_count.c, ft_btree.h	
**  Разрешенные функции: Никакие
**
** ************************************************************************** **
**
** 
**	• Создайте функцию btree_level_count, которая возвращает размер самой большой
**  ветви, переданной в качестве аргумента.
** 
** 
**	• Вот как эта функция должна быть объявлена:
**
**									int		btree_level_count(t_btree *root);
** 
** 
** ************************************************************************** */
/* ************************************************************************** */

#include "ft_btree.h"
# define MAX(a,b) ((a > b) ? a : b)

int		btree_level_count(t_btree *root)
{
	if (root)
		return (1 + MAX(btree_level_count(root->left), \
				btree_level_count(root->right)));
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int left;
	int right;

	left = 0;
	right = 0;
	if (root)
	{
		left = btree_level_count(root->left);
		right = btree_level_count(root->right);
		return (left > right ? left + 1 : right + 1);
	}
	else
		return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_btree.h"

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int		ft_btree_level_count(t_btree *root)
{
	int	count;

	count = 0;
	if (!root)
		return (0);
	if (root->left)
		count = ft_max(count, ft_btree_level_count(root->left));
	if (root->right)
		count = ft_max(count, ft_btree_level_count(root->right));
	return (count + 1);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int ldepth;
	int rdepth;

	if (root)
	{
		ldepth = btree_level_count(root->left);
		rdepth = btree_level_count(root->right);
		return ((ldepth > rdepth) ? ldepth + 1 : rdepth + 1);
	}
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */



#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int left;
	int right;

	if (!root)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	return (1 + ((left > right) ? left : right));
}



/* ************************************************************************** */
/* ************************************************************************** */

int		btree_level_count(t_btree *root)
{
	int a;
	int b;

	if (root == ((void *)0))
		return (0);
	a = btree_level_count(root->left);
	b = btree_level_count(root->right);
	return (1 + (a > b ? a : b));
}