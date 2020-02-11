/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 06:16:39 by adespond          #+#    #+#             */
/*   Updated: 2015/09/20 17:25:58 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_colle.h"

void	cmp_colle(int x, int y, char *save)
{
	int first;

	first = 1;
	if (ft_strcmp(colle00_0(x, y), save) == 0)
		first = ft_put_is_colle("[colle-00]", x, y, first);
	if (ft_strcmp(colle00_1(x, y), save) == 0)
		first = ft_put_is_colle("[colle-01]", x, y, first);
	if (ft_strcmp(colle00_2(x, y), save) == 0)
		first = ft_put_is_colle("[colle-02]", x, y, first);
	if (ft_strcmp(colle00_3(x, y), save) == 0)
		first = ft_put_is_colle("[colle-03]", x, y, first);
	if (ft_strcmp(colle00_4(x, y), save) == 0)
		first = ft_put_is_colle("[colle-04]", x, y, first);
	if (first)
		ft_putstr("aucune");
}

void	count_colle(char *save)
{
	int nbr_x;
	int nbr_y;
	int i;

	i = 0;
	nbr_x = 0;
	nbr_y = 0;
	while (save[i] != '\0')
	{
		if (save[i] == '\n')
			nbr_y++;
		if (save[i] != '\n')
			nbr_x++;
		i++;
	}
	if (nbr_y != 0)
		nbr_x = nbr_x / nbr_y;
	cmp_colle(nbr_x, nbr_y, save);
}

void	read_colle(void)
{
	char	buffer[BUFSIZ];
	char	*save;
	int		ret;
	int		i;

	i = 0;
	save = malloc(BUFSIZ + 1);
	while ((ret = read(0, buffer, 1)))
	{
		save[i] = buffer[0];
		i++;
	}
	save[i] = '\0';
	count_colle(save);
}

int		main(void)
{
	read_colle();
	ft_putchar('\n');
	return (0);
}
