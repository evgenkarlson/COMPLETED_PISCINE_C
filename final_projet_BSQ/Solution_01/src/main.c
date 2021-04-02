/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 09:57:23 by evgenkar          #+#    #+#             */
/*   Updated: 2021/03/09 23:57:20 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"



void	bsq(char *file)
{
	int	fd;

	if (!(((fd = open(file, O_DIRECTORY)) < 0) && \
		((fd = open(file, O_RDONLY)) >= 0) && \
		(prepare_read(fd))))
	{
		write(1, "map error\n", 10);
	}
}


int		main(int argc, char **argv)
{
	if (argc == 2)
		bsq(argv[1]);
	else
		prepare_read(0);
	return (0);
}
