/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:31:31 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 18:47:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if (argc != 3) {
		ft_putchar('\n');
		return (0);
	}

	int i = 0;
	int j = 0;

	while (argv[2][j] != '\0' && i < ft_strlen(argv[1])) 
	{
		if (argv[2][j] == argv[1][i])
			i++;
		j++;
	}
	if (i == ft_strlen(argv[1]))
	{
		ft_putstr(argv[1]);
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}



/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */
