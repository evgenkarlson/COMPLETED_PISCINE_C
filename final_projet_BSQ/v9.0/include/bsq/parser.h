/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:05:56 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/26 16:38:18 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_PARSER_H
# define FT_BSQ_PARSER_H

# include "types.h"
# include "io.h"
# include "ds.h"
# include "compress.h"

extern t_info	*bsq_validate_info(t_info *info);
extern t_info	*bsq_info_ctor(t_info *info, t_reader *reader);
extern int		bsq_read_first(t_reader *reader, t_info *info, t_lbuf **first,
					t_matrix *matrix);

#endif
