/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:05:22 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/26 15:33:40 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "bsq/ds.h"
# include "bsq/io.h"
# include "bsq/parser.h"
# include "bsq/types.h"
# include "bsq/utils.h"
# include "bsq/compress.h"

extern void	bsq_square_check(t_info *info, t_u32 x, t_u32 y, t_u32 s);
t_bool		bsq_solve(t_reader *reader, t_info *info);

#endif
