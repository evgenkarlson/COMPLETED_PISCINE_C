/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/12/11 01:20:56 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex06/
**  Файлы для сдачи: btree_level_count.c, ft_btree.h	
**  Разрешенные функции: malloc, free
**
** ************************************************************************** **
**
** 
**	• Создайте функцию btree_apply_by_level, которая применяет функцию, переданную
**  в качестве аргумента, к каждому узлу дерева. Дерево должно быть просмотрено 
**  уровень за уровнем. Вызываемая функция будет принимать три аргумента :
**
**		◦ Первый аргумент типа 'void *' будет соответствовать элементу узла ;
** 
**		◦ Второй аргумент типа 'int' соответствует уровню, на котором мы 
**      находим: 0 для корня, 1 для детей, 2 для внуков и т.д .;
**
**		◦ Третий аргумент типа 'int' имеет значение 1, если он является первым
**      узлом уровня, или 0 в противном случае.
** 
** 
**	• Вот как эта функция должна быть объявлена:
**
**  void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));
** 
** 
** ************************************************************************** */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int		btree_level_count(t_btree *root)
{
	if (root)
		return (1 + MAX(btree_level_count(root->left), \
				btree_level_count(root->right)));
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#include "ft_btree.h"

static int	btree_level_count(t_btree *root)
{
	int left;
	int right;

	if (!root)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	return (1 + ((left > right) ? left : right));
}

void		btree_process_level(t_btree *root, int *t, int level,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return ;
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

void		btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	int t[3];
	int h;
	int i;

	if (!root)
		return ;
	h = btree_level_count(root);
	i = 0;
	while (i < h)
	{
		t[0] = i;
		t[1] = 1;
		btree_process_level(root, t, ++i, applyf);
	}
}



/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_btree.h"
#include <stdlib.h>

typedef void	(*t_applyf)(void*, int, int);

int		btree_apply_to_lvl(t_btree *root, int lvl, int pos, void *data[2])
{
	int p;

	if (root == NULL)
		return (0);
	if (lvl != 0)
	{
		p = btree_apply_to_lvl(root->left, lvl - 1, pos, data);
		p += btree_apply_to_lvl(root->right, lvl - 1, p, data);
		return (p);
	}
	((t_applyf)data[1])(root->item, *((int *)data[0]), pos == 0);
	return (pos + 1);
}

int		btree_level_count2(t_btree *root)
{
	int a;
	int b;

	if (root == NULL)
		return (0);
	a = btree_level_count2(root->left);
	b = btree_level_count2(root->right);
	return (1 + (a > b ? a : b));
}

void	btree_apply_by_level(t_btree *root, t_applyf applyf)
{
	int c;
	int i;

	c = btree_level_count2(root);
	i = -1;
	while (++i < c)
		btree_apply_to_lvl(root, i, 0, (void *[2]){&i, applyf});
}


/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_btree.h"

int		g_level = 0;

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

void	btree_apply_to_level(t_btree *root, int level, int is_first_elem,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return ;
	if (level == g_level)
		(*applyf)(root->item, level, is_first_elem);
	else
	{
		btree_apply_to_level(root->left, level + 1, is_first_elem, applyf);
		btree_apply_to_level(root->right, level + 1, 0, applyf);
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
	int current_level, int is_first_elem))
{
	int		height;

	height = btree_level_count(root);
	while (g_level < height)
	{
		btree_apply_to_level(root, 0, 1, applyf);
		g_level++;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */
