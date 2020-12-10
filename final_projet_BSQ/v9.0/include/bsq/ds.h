/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:05:36 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/26 16:55:14 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_DS_H
# define BSQ_DS_H

# include "types.h"

# define S_BUFF_SIZE (BUF_SIZE - sizeof(struct s_lbuff*))

extern void		buf_binary_set(t_u8 *matrix, t_u32 pos);
extern t_bool	buf_binary_get(t_u8 *matrix, t_u32 pos);

typedef	struct	s_lbuff
{
	t_u8			buf[S_BUFF_SIZE];
	struct s_lbuff	*next;
}				t_lbuf;

extern t_bool	lbuf_alloca_next(t_u16 i, t_lbuf **buff);
extern void		lbuf_move_next(t_u32 *i, t_u8 div, t_lbuf **buff);

#endif
