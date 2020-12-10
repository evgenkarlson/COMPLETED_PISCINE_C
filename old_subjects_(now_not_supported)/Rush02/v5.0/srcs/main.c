/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 22:40:28 by flklein           #+#    #+#             */
/*   Updated: 2018/09/18 11:41:24 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle2.h"
#include <stdio.h>


char	*read_input(void)
{
	int		r;
	char	buf[BUF_SIZE + 1];
	char	*str;

	if (!(str = (char *)malloc(sizeof(char))))
		return (NULL);
	str[0] = '\0';
	while ((r = read(0, buf, BUF_SIZE)))
	{
		buf[r] = '\0';
		str = ft_strjoin(str, buf);
		str = ft_strjoin(str, "\0");
	}
	return (str);
}

int		main(void)
{
	char	*input;

	input = read_input();
	rush_comp(input);
	return (0);
}
