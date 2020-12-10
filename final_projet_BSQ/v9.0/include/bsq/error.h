/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:06:42 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/26 16:35:06 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_ERROR_H
# define FT_BSQ_ERROR_H

# define BSQ_ASSERT(e, m) ((((e)?(0):bsq_exit(m,sizeof(m)-1))))

# define STANDARD_ERRORS
# ifdef STANDARD_ERRORS
#  define MAP_ERROR "map error\n"
#  define PARSE_ERR MAP_ERROR
#  define PARSE_EXPECT(x) MAP_ERROR
#  define ALLOC_FAIL "\n"
#  define IO_FAIL "\n"
# else
#  define PARSE_ERR "Error: Unexpected char found in the proceeded map.\n"
#  define PARSE_EXPECT(x) "Error: Expected char '" x "' in the proceeded map.\n"
#  define ALLOC_FAIL "Error: Allocation failure.\n"
#  define IO_FAIL "Error: Input/Output failure.\n"
# endif

extern unsigned int	bsq_exit(char *msg, int size);

#endif
