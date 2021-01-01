/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:06:13 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/24 23:06:15 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_TYPES_H
# define FT_BSQ_TYPES_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "utils.h"

# define BUF_SIZE (4096)
# define TRUE (1)
# define FALSE (0)

typedef unsigned int	t_u32;
typedef unsigned short	t_u16;
typedef unsigned char	t_u8;
typedef t_u8			t_bool;

typedef struct			s_bsq_info
{
	t_u8	empty;
	t_u8	obst;
	t_u8	square;
	t_u32	height;
	t_u32	width;
	t_u32	x;
	t_u32	y;
	t_u32	m;
	t_u32	i0;
	t_u32	i1;
	t_u8	i2;
}						t_info;

#endif
