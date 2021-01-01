/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:05:36 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/26 22:08:23 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_IO_H
# define FT_BSQ_IO_H

# include "types.h"

typedef struct	s_reader
{
	t_u8	buf[BUF_SIZE + 1];
	t_u16	cursor;
	t_u16	len;
	t_u8	fd;
}				t_reader;

extern t_reader	*bsq_reader(t_reader *reader, t_u8 fd);
extern t_u8		bsq_next(t_reader *reader);

typedef struct	s_writer
{
	t_u8	buf[BUF_SIZE];
	t_u16	cursor;
}				t_writer;

extern t_writer	bsq_writer(void);
extern void		bsq_write(t_writer *writer, t_u8 c);
extern void		bsq_idea(t_writer *writer);

#endif
