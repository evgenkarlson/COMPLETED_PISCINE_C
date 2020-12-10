/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <dde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 21:35:35 by dde-jesu          #+#    #+#             */
/*   Updated: 2017/07/26 22:21:37 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq/compress.h"

int			print_binary_matrix(t_u8 seg, t_info *info, t_u32 e, t_writer *wter)
{
	t_u8	i;
	t_u32	max;

	i = 0;
	max = (info->height * info->width) - e;
	if (max > 7)
		max = 7;
	while (i < max)
	{
		bsq_print_at((t_bool)((seg >> ((i) % 7)) & 1), info, e + i, wter);
		i++;
	}
	return (7);
}

int			print_repeat_matrix(t_u8 seg, t_info *info, t_u32 e, t_writer *wter)
{
	t_u8	i;
	t_bool	val;
	t_u8	len;

	val = (t_bool)((seg >> 6) & 1);
	len = (t_u8)((seg & 0x3F) + 7);
	i = 0;
	while (i < len)
	{
		bsq_print_at(val, info, e + i, wter);
		i++;
	}
	return (len);
}

void		matrix_print(t_matrix *matrix, t_info *info)
{
	t_u32		i;
	t_lbuf		*lbuf;
	t_u32		e;
	t_writer	writer;

	writer = bsq_writer();
	i = 0;
	e = 0;
	lbuf = matrix->root;
	while (e < info->height * info->width)
	{
		if (((lbuf->buf[i] >> 7) & 1) == BINARY_MATRIX)
			e += print_binary_matrix(lbuf->buf[i], info, e, &writer);
		else
			e += print_repeat_matrix(lbuf->buf[i], info, e, &writer);
		lbuf_move_next(&i, 1, &lbuf);
	}
	bsq_idea(&writer);
}

inline void	bsq_print_at(t_bool val, t_info *info, t_u32 e, t_writer *wter)
{
	t_u32 x;
	t_u32 y;

	x = e % info->width;
	y = e / info->width;
	if (x <= info->x && y <= info->y &&
		x >= (info->x - info->m + 1) && y >= (info->y - info->m + 1))
		bsq_write(wter, info->square);
	else if (val)
		bsq_write(wter, info->empty);
	else
		bsq_write(wter, info->obst);
	if (((e + 1) % info->width) == 0)
		bsq_write(wter, '\n');
}
