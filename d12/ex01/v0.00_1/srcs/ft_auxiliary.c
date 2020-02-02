/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 22:52:06 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/25 22:52:07 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

const char	*ft_strerror(int errnum)
{
	extern const char * const	sys_errlist[];
	extern const int			sys_nerr;

	if (errnum < 0)
		errnum = -errnum;
	if (errnum < sys_nerr)
	{
		return (sys_errlist[errnum]);
	}
	return ("Unknown error");
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i += 1;
	}
}

int			ft_display_custom_error(int eno, char *argv)
{
	ft_putstr(g_progname);
	ft_putstr(": ");
	ft_putstr(argv);
	ft_putstr(": ");
	ft_putstr(ft_strerror(eno));
	ft_putstr("\n");
	return (0);
}
