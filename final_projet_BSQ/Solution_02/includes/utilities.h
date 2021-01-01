/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:33:42 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/20 19:02:59 by fyusuf-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <stdlib.h>
# include "ft_bool.h"

# define UINT unsigned int
# define ULNG unsigned long
# define UCHR unsigned char

# define IN 0
# define OUT 1
# define ERR 2

t_bool	ft_atoi_n_strict(char *str, UINT n, UINT *result);

char	*ft_extend_array(char *orig, char *n_cont, UINT old_len, UINT len);

#endif
