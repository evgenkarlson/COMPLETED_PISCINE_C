/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 23:06:42 by alucas-           #+#    #+#             */
/*   Updated: 2017/07/24 23:06:43 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_UTILS_H
# define FT_BSQ_UTILS_H

# include "error.h"

# ifndef SUCCESS
#  define SUCCESS (0)
# endif

# ifndef FAILURE
#  define FAILURE (1)
# endif

# define UNUSED(x) ((void)(x))
# define MIN(a, b) ((a) < (b) ? (a) : (b))

#endif
