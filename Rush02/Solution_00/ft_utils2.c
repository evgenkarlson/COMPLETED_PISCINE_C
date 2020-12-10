/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:30:28 by cromalde          #+#    #+#             */
/*   Updated: 2020/11/08 16:39:47 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_valid_input(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_spaced(char c)
{
	if ((c == ':') || (c == 32) || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*ft_stread(char *buffer)
{
	int		i;
	int		k;

	buffer = (char *)malloc(35);
	k = 0;
	while ((i = read(0, &buffer[k], 1)))
	{
		if (buffer[k] == '\n')
			break ;
		k++;
	}
	return (buffer);
}
