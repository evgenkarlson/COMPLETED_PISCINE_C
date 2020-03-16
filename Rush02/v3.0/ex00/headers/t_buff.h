/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buff.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:23:44 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 14:23:45 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BUFF_H

# define T_BUFF_H

typedef struct	s_buff
{
	char	*buff;
	int		len;
	size_t	size;
}				t_buff;

void			t_buff_init(t_buff *b, int len);
int				t_buff_extend(t_buff *b);

#endif
