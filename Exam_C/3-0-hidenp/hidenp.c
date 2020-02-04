/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:55:36 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 11:15:36 by exam             ###   ########.fr       */
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
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	check(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s2[j] != '\0')
	{
		if (s1[i] == s2[j])
			i++;
		if (i == ft_strlen(s1))
			return (49);
		j++;
	}
	return (48);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		;
	else
	{
		if (argv[1][0] == '\0')
			ft_putchar(49);
		else
			ft_putchar(check(argv[1], argv[2]));
	}
	ft_putchar('\n');
	return (0);
}



/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */
