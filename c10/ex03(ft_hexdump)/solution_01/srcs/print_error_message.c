/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_message.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:25:22 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/04 22:13:13 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	print_error_message(int errcode, char *str)
{
	if (!errcode)
		return ;
	if (errcode < 0)
	{
		print("hexdump: ");
		print(str);
		print(": No such file or directory");
		print("\n");
	}
	if (errcode == -1)
	{
		print("hexdump: ");
		print(str);
		print(": Bad file descriptor");
		print("\n");
	}
}
