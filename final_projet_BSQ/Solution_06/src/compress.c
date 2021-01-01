/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <dde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:14:04 by dde-jesu          #+#    #+#             */
/*   Updated: 2017/07/26 22:36:28 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq/compress.h"

t_matrix		matrix(void)
{
	t_matrix matrix;

	matrix.lbuf = NULL;
	lbuf_alloca_next(0, &(matrix.lbuf));
	matrix.root = matrix.lbuf;
	matrix.lbuf->buf[0] = 0;
	matrix.cursor = 0;
	return (matrix);
}

void			try_change_mode(t_matrix *matrix, t_bool value)
{
	t_u8 current;

	matrix->lbuf->buf[matrix->cursor / 7] = 0;
	current = matrix->lbuf->buf[(matrix->cursor / 7) - 1];
	if ((value && current == 0x7F) || (!value && current == 0x00))
	{
		matrix->lbuf->buf[(matrix->cursor / 7) - 1] =
			(t_u8)((REPEAT_MATRIX << 7) | (value << 6));
		matrix->cursor = (matrix->cursor / 7 - 1) * 7 + 1;
	}
}

inline t_bool	matrix_write(t_matrix *matrix, t_bool value)
{
	t_bool mode;

	if (matrix->cursor % 7 == 0 && matrix->cursor > 6)
		try_change_mode(matrix, value);
	mode = (t_bool)((matrix->lbuf->buf[matrix->cursor / 7] >> 7) & 1);
	if (mode == BINARY_MATRIX && ++matrix->cursor && value)
		matrix->lbuf->buf[(matrix->cursor - 1) / 7] |=
			1 << ((matrix->cursor - 1) % 7);
	else if (mode == REPEAT_MATRIX)
	{
		if (value != ((matrix->lbuf->buf[matrix->cursor / 7] >> 6) & 1)
			|| (matrix->lbuf->buf[matrix->cursor / 7] & 0x3F) == 0x3F)
		{
			matrix->cursor = (matrix->cursor / 7 + 1) * 7;
			return (matrix_write(matrix, value));
		}
		matrix->lbuf->buf[matrix->cursor / 7]++;
	}
	if (lbuf_alloca_next((t_u16)(matrix->cursor / 7), &(matrix->lbuf)))
	{
		matrix->lbuf->buf[0] = 0;
		matrix->cursor = 0;
	}
	return (value);
}
