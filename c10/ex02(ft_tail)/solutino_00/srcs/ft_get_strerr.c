/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_strerr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/03 23:59:39 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

const char	*ft_get_strerr(int errnum)
{
	extern const char * const	sys_errlist[];
	extern int					sys_nerr;

	if (errnum < 0)
		errnum = -errnum;
	if (errnum < sys_nerr)
		return (sys_errlist[errnum]);
	return ((const char *)"Unknown error");
}