/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 11:02:43 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/17 11:02:43 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_number_dictionary.h"
#include "ft_boolean.h"
#include "ft_io.h"
#include "ft_to.h"
#include "ft_str.h"

t_error		process(char *to_convert, t_dict *dict)
{
	ULNG	number;
	t_bool	put_space;

	number = ft_atoi_strict(to_convert);
	if (number == (ULNG)-1)
		return (invalid_number);
	if (!ft_itow(dict, number, 0, false))
		return (fail_convert);
	put_space = false;
	ft_itow(dict, number, &put_space, true);
	return (none);
}

void		show_error(t_error error)
{
	if (error == none)
		return ;
	if (error == dict_parsing)
		ft_str_write_to(ERR, "Dict Error");
	else
		ft_str_write_to(ERR, "Error");
	ft_str_write_to(ERR, "\n");
}

t_error		main_delegate(int argc, char **argv, char **to_conv, t_dict *dict)
{
	if (argc == 3)
	{
		*dict = ft_load_dictionary(argv[1]);
		*to_conv = argv[2];
	}
	else if (argc == 2)
	{
		*dict = ft_load_default_dictionary();
		*to_conv = argv[1];
	}
	else
		return (generic);
	return (none);
}

int			main(int argc, char **argv)
{
	t_error	error;
	t_dict	dict;
	char	*to_convert;

	error = main_delegate(argc, argv, &to_convert, &dict);
	if (error == none && !dict.valid)
		error = dict_parsing;
	if (error == none)
		error = process(to_convert, &dict);
	show_error(error);
	if (error == none)
		ft_str_write_to(OUT, "\n");
	if (dict.valid)
		ft_free_dictionary(&dict);
	return (error ? 1 : 0);
}
