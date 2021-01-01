/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <dde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:15:18 by dde-jesu          #+#    #+#             */
/*   Updated: 2017/07/26 22:13:25 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_COMPRESS_H
# define BSQ_COMPRESS_H

# include "types.h"
# include "ds.h"
# include "io.h"

typedef struct	s_matrix
{
	t_lbuf	*lbuf;
	t_lbuf	*root;
	t_u32	cursor;
}				t_matrix;

# define BINARY_MATRIX 0
# define REPEAT_MATRIX 1

extern t_matrix	matrix();
extern t_bool	matrix_write(t_matrix *matrix, t_bool value);
void			matrix_print(t_matrix *matrix, t_info *info);
extern void		bsq_print_at(t_bool val, t_info *info, t_u32 e,
					t_writer *writer);

#endif
