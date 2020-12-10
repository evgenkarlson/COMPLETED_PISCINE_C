/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:30:19 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/26 16:54:49 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq/ds.h"

inline void		buf_binary_set(t_u8 *matrix, t_u32 pos)
{
	if (pos % 8 == 0)
		matrix[pos / 8] = 0;
	matrix[pos / 8] |= (1 << (pos % 8));
}

inline t_bool	buf_binary_get(t_u8 *matrix, t_u32 pos)
{
	return (t_bool)((matrix[pos / 8] >> (pos % 8)) & 1);
}

inline t_bool	lbuf_alloca_next(t_u16 i, t_lbuf **buff)
{
	if (i > S_BUFF_SIZE)
	{
		BSQ_ASSERT((*buff)->next = malloc(sizeof(t_lbuf)), ALLOC_FAIL);
		*buff = (*buff)->next;
		return (TRUE);
	}
	if (*buff == NULL)
	{
		BSQ_ASSERT(*buff = malloc(sizeof(t_lbuf)), ALLOC_FAIL);
		return (TRUE);
	}
	return (FALSE);
}

inline void		lbuf_move_next(t_u32 *i, t_u8 div, t_lbuf **buff)
{
	t_lbuf *prev;

	if ((++*i) / div > S_BUFF_SIZE)
	{
		prev = *buff;
		*buff = prev->next;
		free(prev);
		*i = 0;
	}
}
