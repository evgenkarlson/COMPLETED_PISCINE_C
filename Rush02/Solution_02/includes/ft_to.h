/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:22:22 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/17 12:22:22 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TO_H
# define FT_TO_H

# include <ft_boolean.h>

# include "ft_short_types.h"

int		ft_atoi(char *str);

ULNG	ft_atoi_strict(char *str);

t_bool	ft_itow(t_dict *dict, ULNG number, t_bool *put_space, t_bool print);

#endif
