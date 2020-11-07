/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_custom_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 00:58:47 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_display_custom_error(int eno, char *argv)
{
	ft_putstr(g_progname);
	ft_putstr(": ");
	ft_putstr(argv);
	ft_putstr(": ");
	ft_putstr((char *)ft_get_strerr(eno));
	ft_putchar('\n');
}