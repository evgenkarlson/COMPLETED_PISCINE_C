/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:17:57 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/17 15:17:57 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_number_dictionary.h"

void	debug_dump_dictionary(t_dict dict)
{
	int		index;

	index = 0;
	while (index < dict.size)
	{
		printf("dict.entries[%d]\n", index);
		printf("    | value : %lu\n", dict.entries[index].value);
		printf("    | str   : $%s$\n", dict.entries[index].str);
		index++;
	}
	fflush(stdout);
}
