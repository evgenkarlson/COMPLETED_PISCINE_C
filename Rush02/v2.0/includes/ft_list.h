/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbufnoir <rbufnoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 14:02:28 by rbufnoir          #+#    #+#             */
/*   Updated: 2014/07/20 15:03:13 by rbufnoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JP_LIST_H
# define JP_LIST_H

# include <stdlib.h>

typedef	struct		s_list
{
	struct s_list	*next;
	char			str[129];
}					t_list;

t_list				*jp_create_elem(char *str);
void				jp_list_push_back(t_list **begin_list, char *str);
int					jp_list_size(t_list **begin_list);

#endif
