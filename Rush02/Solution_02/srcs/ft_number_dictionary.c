/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_dictionary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:03:18 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/17 11:03:18 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_number_dictionary.h"

t_dict	ft_load_default_dictionary(void)
{
	return (ft_load_dictionary(ENGLISH_DICT));
}

t_dict	ft_load_dictionary(char *path)
{
	int				size;
	t_dict_entry	*entries;
	t_dict			dict;

	dict = (t_dict){path, false, 0, 0};
	size = ft_count_valid_line(path);
	if (size == INVALID)
		return (dict);
	if (!(entries = malloc((size + 1) * sizeof(t_dict_entry))))
		return (dict);
	dict.size = size;
	dict.entries = entries;
	dict.valid = ft_load_valid_line(path, size, &dict);
	if (dict.valid)
		ft_sort_dictionary(&dict);
	return (dict);
}

void	ft_free_dictionary(t_dict *dict)
{
	int		index;

	index = 0;
	while (index < dict->size)
	{
		free(dict->entries[index].str);
		index++;
	}
}
