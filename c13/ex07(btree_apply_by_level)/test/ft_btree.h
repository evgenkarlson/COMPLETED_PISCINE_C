/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/12/25 18:21:20 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_BTREE_H
# define FT_BTREE_H
# define MAX(a,b) ((a > b) ? a : b)

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

t_btree				*btree_create_node(void *item);
void				btree_apply_by_level(t_btree *root, void (*applyf)(void *item, \
										int current_level, int is_first_elem));

#endif


/* ************************************************************************** */
/* ************************************************************************** */
