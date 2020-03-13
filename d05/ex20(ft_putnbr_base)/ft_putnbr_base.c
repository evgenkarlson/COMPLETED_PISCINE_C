/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 
• Create a function that displays a number in a base system onscreen.
• This number is given in the shape of an int, and the radix in the shape of a string of characters.
• The base-system contains all useable symbols to display that number :
	◦ 0123456789 is the commonly used base system to represent decimal numbers;
	◦ 01 is a binary base system ;
	◦ 0123456789ABCDEF an hexadecimal base system ;
	◦ poneyvif is an octal base system.
• The function must handle negative numbers.
• If there’s an invalid argument, nothing should be displayed. Examples of invalid arguments :
	◦ base is empty or size of 1;
	◦ base contains the same character twice ;
	◦ base contains + or - ;
	◦ etc.


• Создайте функцию, которая отображает число в базовой системе на экране.
• Это число дается в форме целого числа, а основание - в виде строки символов.
• Базовая система содержит все используемые символы для отображения этого числа:
	◦ 0123456789 - широко используемая базовая система для представления десятичных чисел;
	◦ 01 - двоичная базовая система;
	◦ 0123456789ABCDEF шестнадцатеричная базовая система;
	◦ poneyvif - это восьмеричная базовая система.
• Функция должна обрабатывать отрицательные числа.
• Если указан неверный аргумент, ничего не должно отображаться. Примеры неверных аргументов:
	◦ база пуста или имеет размер 1;
	◦ база содержит один и тот же символ дважды;
	◦ база содержит + или -;
	◦ и т. Д.

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void		ft_putchar(char c);

/* ************************************************************************** */

static int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z')))
			return (0);
		while (base[z])
			if (base[i] == base[z++])
				return (0);
		i++;
	}
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		size;
	int		n[10];

	i = 0;
	size = 0;
	if (!check_base(base))
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	while (base[size])
		size++;
	while (nbr)
	{
		n[i] = nbr % size;
		nbr /= size;
		i++;
	}
	while (i > 0)
		ft_putchar(base[n[--i]]);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
int		check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
}
