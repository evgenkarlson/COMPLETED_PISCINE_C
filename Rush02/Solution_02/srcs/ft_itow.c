/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:44:01 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/17 15:44:01 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_boolean.h"
#include "ft_number_dictionary.h"
#include "ft_str.h"

#define NOT_FOUND -1

int		ft_resolve_dict_entry_index(t_dict *dict, ULNG number)
{
	int		index;

	index = 0;
	while (index < dict->size)
	{
		if (dict->entries[index].value == number)
			return (index);
		index++;
	}
	return (NOT_FOUND);
}

t_bool	ft_itow_is_value_power_of_ten(ULNG number)
{
	ULNG		power;

	power = 1;
	while (power <= number)
	{
		if (power == number)
			return (true);
		power *= 10;
	}
	return (false);
}

void	ft_itow_print_if(t_bool print, t_bool *put_space, char *str)
{
	if (!print)
		return ;
	if (*put_space)
		ft_str_write(" ");
	*put_space = true;
	ft_str_write(str);
}

t_bool	ft_itow_short(t_dict *dict, ULNG number, t_bool *put_sp, t_bool prnt)
{
	int		dict_index;

	dict_index = ft_resolve_dict_entry_index(dict, number);
	if (dict_index == NOT_FOUND)
		return (false);
	ft_itow_print_if(prnt, put_sp, dict->entries[dict_index].str);
	return (true);
}

t_bool	ft_itow(t_dict *dict, ULNG number, t_bool *put_space, t_bool print)
{
	int		index;
	ULNG	mult;
	ULNG	value;

	if ((number <= 20 && ft_itow_short(dict, number, 0, false))
			|| (ft_resolve_dict_entry_index(dict, number) != NOT_FOUND
					&& !ft_itow_is_value_power_of_ten(number)))
		return (ft_itow_short(dict, number, put_space, print));
	index = dict->size - 1;
	while ((value = dict->entries[index].value) != 0)
	{
		if (number % value != number)
		{
			mult = number / value;
			if (value > 99)
				if (!ft_itow(dict, mult, put_space, print))
					return (false);
			ft_itow_print_if(print, put_space, dict->entries[index].str);
			if (number - mult * value == 0)
				return (true);
			return (ft_itow(dict, number - mult * value, put_space, print));
		}
		index--;
	}
	return (true);
}
