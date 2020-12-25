/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/12/25 22:20:32 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex07/
**  Файлы для сдачи: btree_apply_by_level.c, ft_btree.h
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
**      находимcя: 0 для корня, 1 для детей, 2 для внуков и т.д .;
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
# define MAX(a,b) ((a > b) ? a : b)

int		btree_level_count(t_btree *root)
{
	if (root)
		return (1 + MAX(btree_level_count(root->left), \
				btree_level_count(root->right)));
	return (0);
}

void	btree_process_level(t_btree *root, int *t, int level,
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

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	int t[3];
	int h;
	int i;

	if (root)
	{
		h = btree_level_count(root);
		i = 0;
		while (i < h)
		{
			t[0] = i;
			t[1] = 1;
			btree_process_level(root, t, ++i, applyf);
		}
	}
}


/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_btree.h"
# define MAX(a,b) ((a > b) ? a : b)

typedef void	(*t_applyf)(void*, int, int);

int		btree_apply_to_lvl(t_btree *root, int lvl, int pos, void *data[2])
{
	int p;

	if (!root)
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


int		btree_level_count(t_btree *root)
{
	if (root)
		return (1 + MAX(btree_level_count(root->left), \
				btree_level_count(root->right)));
	return (0);
}


void	btree_apply_by_level(t_btree *root, t_applyf applyf)
{
	int count;
	int i;

	count = btree_level_count(root);
	i = -1;
	while (++i < count)
		btree_apply_to_lvl(root, i, 0, (void *[2]){&i, applyf});
}


/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_btree.h"
# define MAX(a,b) ((a > b) ? a : b)


int		g_level = 0;


int		btree_level_count(t_btree *root)
{
	if (root)
		return (1 + MAX(btree_level_count(root->left), \
				btree_level_count(root->right)));
	return (0);
}


void	btree_apply_to_level(t_btree *root, int level, int is_first_elem,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (root)
	{
		if (level == g_level)
			(*applyf)(root->item, level, is_first_elem);
		else
		{
			btree_apply_to_level(root->left, level + 1, is_first_elem, applyf);
			btree_apply_to_level(root->right, level + 1, 0, applyf);
		}
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

void	call(t_btree *root, int current_level, int *levels,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	is_first_elem;

	is_first_elem = 1;
	if (levels[current_level] == 1)
		is_first_elem = 0;
	else
		levels[current_level] = 1;
	applyf(root->item, current_level, is_first_elem);
	if (root->left)
		call(root->left, current_level + 1, levels, applyf);
	if (root->right)
		call(root->right, current_level + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	int	count;
	int	*levels;
	int	i;

	if (root)
	{
		count = ft_btree_level_count(root);
		if (!(levels = (int*)malloc(sizeof(int) * count)))
			return ;
		i = 0;
		while (i < count)
			levels[i++] = 0;
		call(root, 0, levels, applyf);
	}
}