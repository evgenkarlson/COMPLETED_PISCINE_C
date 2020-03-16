/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:23:36 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 14:23:37 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"
#include "t_buff.h"

char	*re_alloc(char *ptr, int n)
{
	char	*ret;

	if (!(ret = malloc(sizeof(char) * n)))
		return (0);
	ft_strcpy(ret, ptr);
	free(ptr);
	return (ret);
}

void	t_buff_init(t_buff *b, int len)
{
	b->len = len;
	b->size = sizeof(char);
	b->buff = malloc(b->size * len + 1);
}

int		t_buff_extend(t_buff *b)
{
	b->len *= 2;
	b->buff = re_alloc(b->buff, b->len + 1);
	if (!b->buff)
		return (-1);
	return (b->len);
}
