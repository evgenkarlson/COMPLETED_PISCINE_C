/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:38:17 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 20:02:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define ISLETTER(c) ((c > 64 && c < 91) || (c > 96 && c < 123)) ? 1 : 0

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

char high(char c)
{
	if (c > 96 && c < 123)
		c = c - 32;
	return (c);
}

char low(char c)
{
	if (c > 64 && c < 91)
		c+=32;
	return (c);
}

char *cap(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if ((i == 0) && (str[i] > 96 && str[i] < 123))
			str[i] = str[i] - 32;
		else if ((ISLETTER(str[i])) && (str[i -1] == ' ' || str[i-1] == '\t'))
			str[i] = high(str[i]);
		else if ((ISLETTER(str[i])) && (str[i - 1] != ' ' || str[i -1] != '\t'))
		{
			if (i != 0)
				str[i] = low(str[i]);
		}
		i++;
	}
	return (str);
}

int main(int argc, char **argv)
{
	if (argc == 1) {
		ft_putchar('\n');
		return (0);
	}

	int i = 1;
	while (i < argc)
	{
		ft_putstr(cap(argv[i]));
		ft_putchar('\n');
		i++;
	}
	return (0);

}




/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */
