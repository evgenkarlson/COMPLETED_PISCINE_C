/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 13:30:19 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/26 22:21:18 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq/io.h"

inline t_reader	*bsq_reader(t_reader *reader, t_u8 fd)
{
	ssize_t		rlen;

	if (fd < 0)
		return (NULL);
	if ((rlen = read(fd, reader->buf, BUF_SIZE)) <= 0)
		return (NULL);
	reader->len = (t_u16)rlen;
	reader->buf[reader->len] = '\0';
	reader->cursor = 0;
	reader->fd = fd;
	return (reader);
}

inline t_u8		bsq_next(t_reader *reader)
{
	t_u8	c;
	ssize_t	rlen;

	if ((c = reader->buf[reader->cursor++]))
		return (c);
	BSQ_ASSERT((rlen = read(reader->fd, reader->buf, BUF_SIZE)) != -1, IO_FAIL);
	reader->len = (t_u16)rlen;
	reader->buf[reader->len] = '\0';
	reader->cursor = 0;
	if (reader->len)
		return (reader->buf[reader->cursor++]);
	return ('\0');
}

inline t_writer	bsq_writer(void)
{
	t_writer writer;

	writer.cursor = 0;
	return (writer);
}

inline void		bsq_idea(t_writer *writer)
{
	write(1, writer->buf, writer->cursor);
	writer->cursor = 0;
}

inline void		bsq_write(t_writer *writer, t_u8 c)
{
	if (writer->cursor >= BUF_SIZE)
		bsq_idea(writer);
	writer->buf[writer->cursor++] = c;
}
