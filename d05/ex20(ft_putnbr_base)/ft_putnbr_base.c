/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/23 11:11:54 by evgenkarlson     ###   ########.fr       */
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


• Создайте функцию, которая отображает число в нужной базовой системе счисления на экране.
• Это число дается в форме целого числа, а система счисления - в виде строки символов.
• Базовая система счисления содержит все используемые символы для отображения этого числа:
	◦ 0123456789 - широко используемая базовая десятична система для представления десятичных чисел;
	◦ 01 - двоичная базовая система;
	◦ 0123456789ABCDEF шестнадцатеричная базовая система;
	◦ poneyvif - это восьмеричная базовая система.
• Функция должна обрабатывать отрицательные числа.
• Если указан неверный аргумент, ничего не должно отображаться. Примеры неверных аргументов:
	◦ база пуста или имеет размер 1;
	◦ база содержит один и тот же символ дважды;
	◦ база содержит + или -;
	◦ и т. Д.



   ***********************************P.S.***********************************
   
	Функция берет число из первого аргумента и печатает его в той системе счисления, 
	которую мы укажем во втором аргументе. Второй аргумент должен быть массивом символов,
	который будет содержать данные базого основания нужной системы счисления,
	которые будут использоваться как формат для печати целого числа.

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void		ft_putchar(char c);

/* ************************************************************************** */

static int	ft_check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z')))
			return (0);
		z = i + 1;
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (i);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		base_type;
	int		n[10];

	i = 0;
	base_type = ft_check_base(base);
	if (base_type)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (nbr)
		{
			n[i] = nbr % base_type;
			nbr /= base_type;
			i++;
		}
		while (i > 0)
			ft_putchar(base[n[--i]]);
	}
	
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c);

/* ************************************************************************** */

int		is_pr2(char c)
{
	return (c >= 32 && c <= 126);
}

int		validate_base(char *base)
{
	char	*ptr;
	int		i;
	int		vals[95];

	ptr = base;
	i = -1;
	while (i++ < 95)
		vals[i] = 0;
	i = 0;
	while (*ptr)
	{
		if (!is_pr2(*ptr))
			return (0);
		if (*ptr == '+' || *ptr == '-')
			return (0);
		if (vals[(*ptr) - 32])
			return (0);
		vals[(*ptr) - 32] = 1;
		i++;
		ptr++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_put_negative_base(int nb, char *base, int basen)
{
	int a;
	int b;

	if (nb)
	{
		a = nb / basen;
		b = nb % basen;
		ft_put_negative_base(a, base, basen);
		ft_putchar(*(base - b));
	}

}

void	ft_putnbr_base(int nbr, char *base)
{
	int basen;

	basen = validate_base(base);
	if (basen)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			ft_put_negative_base(nbr, base, basen);
		}
		else
			ft_put_negative_base(-nbr, base, basen);
	}

}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c);

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
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_type;
	int	nbr_final[100];
	int	i;

	i = 0;
	base_type = check_base(base);
	if (base_type)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (nbr)
		{
			nbr_final[i] = nbr % base_type;
			nbr = nbr / base_type;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



void	ft_putchar(char c);

/* ************************************************************************** */


static int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++ != '\0')
	{
		len++;
	}
	return (len);
}

static void	ft_putnbr_base_n(int nbr, char *base, int n)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		if (nbr == -2147483648)
		{
			ft_putnbr_base_n(2, base, n);
			ft_putnbr_base_n(147483648, base, n);
		}
		else
			ft_putnbr_base_n(-nbr, base, n);
	}
	else if (nbr < n)
		ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base_n(nbr / n, base, n);
		ft_putchar(base[nbr % n]);
	}
}

static int	ft_strchar(char *str, char to_find)
{
	while (*str != '\0')
		if (to_find == *str++)
			return (1);
	return (0);
}

static int	ft_check_base(char *base, int n)
{
	while (n)
	{
		if (base[n] == '+' || base[n] == '-')
			return (0);
		if (ft_strchar(base + n + 1, base[n]))
			return (0);
		--n;
	}
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int		base_len;

	base_len = ft_strlen(base);
	if (base && (base_len > 1) && ft_check_base(base, base_len))
		ft_putnbr_base_n(nbr, base, base_len);
}