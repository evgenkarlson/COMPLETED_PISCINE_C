/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:45:16 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 13:45:17 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "read_stdin.h"
#include "match_rush.h"

void	print_data(char **data)
{
	while (*data)
	{
		ft_putstr(*data);
		ft_putchar('\n');
	}
}

int		main(void)
{
	char *str;
	char **data;

	str = read_stdin();
	data = ft_split_whitespaces(str);
	match_shape(data);
	return (0);
}
