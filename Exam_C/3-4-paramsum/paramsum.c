/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:50:50 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 18:56:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	char **thxgcc;

	thxgcc = argv;
	if (argc == 1) 
		ft_putchar(48);
	else
		ft_putchar(argc - 1 + 48);
	ft_putchar('\n');
	return (0);
}
