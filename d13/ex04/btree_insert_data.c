/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_btree.h"
#include <unistd.h>

int     ft_strcmp(void *v1, void *v2)
{
	char    *s1;
	char    *s2;

	s1 = (char *)v1;
	s2 = (char *)v2;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void        ft_putstr(void *v)
{
	char *str;

	str = (char *)v;
	while (*str)
		write(1, str++, 1);
}

void    btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		(*applyf)(root->item);
		if (root->left)
			btree_apply_prefix(root->left, applyf);
		if (root->right)
			btree_apply_prefix(root->right, applyf);
	}
}

t_btree *btree_create_node(void *item)
{
	t_btree *btree;

	btree = NULL;
	btree = (t_btree*)malloc(sizeof(t_btree));
	if (btree)
	{
		btree->left = 0;
		btree->right = 0;
		btree->item = item;
	}
	return (btree);
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		btree_create_node(item);
	else if ((*cmpf)(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}

int main()
{
	t_btree *root;

	root = NULL;
	btree_insert_data(&root, "5", &ft_strcmp);
	btree_insert_data(&root, "3", &ft_strcmp);
	btree_insert_data(&root, "8", &ft_strcmp);
	btree_insert_data(&root, "4", &ft_strcmp);
	btree_insert_data(&root, "1", &ft_strcmp);
	btree_insert_data(&root, "9", &ft_strcmp);
	btree_insert_data(&root, "0", &ft_strcmp);
	btree_insert_data(&root, "7", &ft_strcmp);
	btree_insert_data(&root, "6", &ft_strcmp);
	btree_insert_data(&root, "2", &ft_strcmp);
	btree_insert_data(&root, "4", &ft_strcmp);
	btree_insert_data(&root, "7", &ft_strcmp);
	ft_putstr("<");
	btree_apply_prefix(root, &ft_putstr);
	ft_putstr("\n>531024487679\n");
	/* ft_putstr("<"); */
	/* btree_apply_infix(root, &ft_putstr); */
	/* ft_putstr("\n>012344567789\n"); */
	/* ft_putstr("<"); */
	/* btree_apply_suffix(root, &ft_putstr); */
	/* ft_putstr("\n>021443677985\n"); */
	return (0);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



void	btree_insert_data(t_btree **root, void *item, \
							int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
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


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
