/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/29 13:58:11 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* - Create a function that displays the number entered as a parameter. 
The function has to be able to display all possible values within an int type 
variable. */

/* - Создайте функцию, которая отображает число, введенное в качестве параметра.
 Функция должна иметь возможность отображать все возможные значения в переменной 
 типа int. */


/* - Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую */

/* ************************************************************************** */

void	ft_putchar(char c);

/* ************************************************************************** */

void	ft_putnbr(int nb)
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + '0');
		temp %= size;
		size /= 10;
	}
}


/* ************************************************************************** */
/* *********************************_ИЛИ_************************************ */
/* ************************************************************************** */

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}


/* ************************************************************************** */
/* *********************************_ИЛИ_************************************ */
/* ************************************************************************** */


void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}


/* ************************************************************************** */
/* *********************************_ИЛИ_************************************ */
/* ************************************************************************** */


void	ft_printnbr(int x[])
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (i < 10)
	{
		if (b == 1)
		{
			ft_putchar(x[i] + 48);
		}
		else
		{
			if (x[i] > 0)
			{
				b = 1;
				ft_putchar(x[i] + 48);
			}
		}
		i++;
	}
}

void	ft_preventoverflow(void)
{
	ft_putchar('-');
	ft_putchar('2');
	ft_putchar('1');
	ft_putchar('4');
	ft_putchar('7');
	ft_putchar('4');
	ft_putchar('8');
	ft_putchar('3');
	ft_putchar('6');
	ft_putchar('4');
	ft_putchar('8');
}

void	ft_fillarray(int x[], int nb)
{
	int t;

	t = 9;
	while (t >= 0)
	{
		x[t] = nb % 10;
		nb /= 10;
		t--;
	}
}

void	ft_putnbr(int nb)
{
	int x[10];

	if (nb == 0)
		ft_putchar('0');
	else
	{
		if (nb == -2147483648)
			ft_preventoverflow();
		else
		{
			if (nb < 0)
			{
				ft_putchar('-');
				nb = nb + -2 * nb;
			}
			ft_fillarray(x, nb);
			ft_printnbr(x);
		}
	}
}


/* ************************************************************************** */
