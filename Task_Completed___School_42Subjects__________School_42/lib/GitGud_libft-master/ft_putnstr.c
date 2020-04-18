/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 16:05:33 by varnaud           #+#    #+#             */
/*   Updated: 2016/10/30 16:07:54 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_putnstr(const char *str, size_t n)
{
	while (*str && n)
	{
		ft_putchar(*str);
		str++;
		n--;
	}
}
