/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/11 23:10:51 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**
**  •  Создайте функцию, которая отображает число в нужной базовой системе 
**  счисления на экране.
**
**
**  •  В агрументах фунции это число дается нам в форме целого числа, а  
**  система счисления дается нам - в виде 'строки символов'.
**
**
**  •  Базовая система счисления содержит все используемые символы для 
**  отображения этого числа:
**  	◦ 0123456789 - широко используемая базовая десятична система для 
**      представления десятичных чисел;
**  	◦ 01 - двоичная базовая система;
**  	◦ 0123456789ABCDEF шестнадцатеричная базовая система;
**  	◦ poneyvif - это восьмеричная базовая система.
**
**
**  •  Функция должна обрабатывать отрицательные числа.
**
**  •  Если указан неверный аргумент, ничего не должно отображаться. Примеры
**  неверных аргументов:
**  	◦ Если база, отражающая систему счисления, пуста или имеет размер 1;
**  	◦ Если база, отражающая систему счисления, содержит один и тот же символ дважды;
**  	◦ Если база, отражающая систему счисления, содержит символы '+' или '-';
**  	◦ и т. д.
**  
**   
**  •  Ваша функция должна быть объявлена ​​следующим образом:
**  
**  	void		ft_putnbr_base(int nbr, char *base);
**  
** 
** ***********************************P.S.***********************************
**  
**  Функция берет число из первого аргумента и печатает его в той системе счисления, 
**  которую мы укажем во втором аргументе. Второй аргумент должен быть массивом символов,
**  который будет содержать данные базого основания нужной системы счисления,
**  которые будут использоваться как формат для печати целого числа.
**
**  
** ************************************************************************** **
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
/* ************************************************************************** */

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
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
	int		n[16];

	i = 0;
	if ((base_type = ft_check_base(base)))
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


void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
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


int		ft_get_len_future_nbr(int nbr, int base_type)
{
	int	size;

	if (base_type)
	{
		size = 1;
		while ((nbr /= base_type) > 0)
			size++;
	}
	return (size);
}

void	ft_conv_nbr(int nbr, int length, char *base, int base_type)
{
	int		i;
	int		n[length];

	i = 0;
	while (nbr)
	{
		n[i] = nbr % base_type;
		nbr /= base_type;
		i++;
	}
	while (i > 0)
		ft_putchar(base[n[--i]]);
	
}


void	ft_putnbr_base(int nbr, char *base)
{
	int		base_type;

	if ((base_type = ft_check_base(base)))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		ft_conv_nbr(nbr, ft_get_len_future_nbr(nbr, base_type), base, base_type);
	}
}


/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

	if ((basen = validate_base(base)))
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int		ft_check_base(char *base)
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
	if ((base_type = ft_check_base(base)))
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



void	ft_putchar(char c)
{
	write(1, &c, 1);
}


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