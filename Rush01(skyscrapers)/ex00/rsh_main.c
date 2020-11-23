/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/23 12:10:53 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rshbas.h"
#include "rshini.h"
#include "rshchk.h"
#include "rshmtx.h"

int		main(int argc, char *argv[])
{
	if (argc == 2 && ft_strlen(argv[1]) == 31 && argv[1][0] >= '1' &&
			argv[1][0] <= '4')
		ft_initialization(argv[1]);
	else
		ft_msg_error();
	return (0);
}
