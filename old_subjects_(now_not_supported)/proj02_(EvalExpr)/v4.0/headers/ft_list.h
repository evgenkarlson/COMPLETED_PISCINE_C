/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:30:36 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:30:37 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H

# define FT_LIST_H

typedef struct		s_list
{
	struct s_list	*next;
	char			*str;
	int				value;
}					t_list;

t_list				*ft_create_elem(char *data);

void				print_ll(t_list *ll);
void				ft_list_push_back(t_list **begin_list, char *data);
int					ft_list_size(t_list *begin_list);
void				ft_list_delete_next(t_list *node);

#endif
