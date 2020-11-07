/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 14:42:47 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** 
**  
**  • Создать функцию, которая отображает область памяти на экране.
**  • Отображение этой области памяти должно быть разбито на три столбца:
**  	◦ Шестнадцатеричный адрес первого символа первой строки;
**  	◦ Содержание в шестнадцатеричном формате;
**  	◦ Содержание печатных символов.
**  • Если символ недоступен для печати, он будет заменен точкой.
**  • Каждая строка должна содержать шестнадцать символов.
**  • Если размер равен 0, ничего не должно отображаться.
**  • Функция должна вернуть адрес.
**  
** ************************************************************************** **
**  
**  • Example(Пример):
**  
**  $> ./ft_print_memory
**  000000010a161f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin
**  000000010a161f50: 6368 6573 090a 0963 2020 6573 7420 666f ches...c est fo
**  000000010a161f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on
**  000000010a161f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.
**  000000010a161f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..
**  000000010a161f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000     ..lol.lol. .
**  $> ./ft_print_memory | cat -te
**  0000000107ff9f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin$
**  0000000107ff9f50: 6368 6573 090a 0963 2020 6573 7420 666f ches...c est fo$
**  0000000107ff9f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on $
**  0000000107ff9f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.$
**  0000000107ff9f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..$
**  0000000107ff9f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000     ..lol.lol. .$
**  $>
**  
**  
** ************************************************************************** */
/* ************************************************************************** */


void		ft_putchar(char c)
{
	write(1, &c, 1);
}



void	ft_print_address(int nbr, char *hex)
{
	int		add[9];											
	int 	i;
	int		j;
	int 	base_type;

	i = 0;
	j = 8; 
	base_type = 16;
	if(nbr == 0)
	{
		while(j-- > 0)
			ft_putchar('0');
	}
	else
	{
		while (nbr)
		{
			add[i] = nbr % base_type;
			nbr /= base_type;
			i++;
		}
		j = (8 - i);
		while(j-- > 0)
			ft_putchar('0');
		while (i > 0)
			ft_putchar(hex[add[--i]]);
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*p;
	char			*hex;


	i = 0;
	p = (unsigned char *)addr;
	hex = "0123456789abcdef";
	while (i < size)
	{
		j = 0;
		ft_print_address(i, hex);
		while (j < 16 && i + j < size)
		{
			ft_putchar((char)hex[(*(p + i + j) / 16) % 16]);
			ft_putchar((char)hex[*(p + i + j) % 16]);
			if (j % 2)										
				ft_putchar(' ');
			j++;
		}
		while (j < 16)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			if (j % 2)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (*(p + i + j) >= 32 && *(p + i + j) <= 126)
				ft_putchar((char)*(p + i + j));
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i += 16;
	}
	return (addr + i);
}



/* ************************************************************************** */
/* ************************************************************************** */


void		ft_putchar(char c)
{
	write(1, &c, 1);
}


void 	ft_print_address(int nbr, char *hex)
{
	int		add[9];											
	int 	i;
	int		j;
	int 	base_type;

	i = 0;
	j = 8; 
	base_type = 16;
	if(nbr == 0)
	{
		while(j-- > 0)
			ft_putchar('0');
	}
	else
	{
		while (nbr)
		{
			add[i] = nbr % base_type;
			nbr /= base_type;
			i++;
		}
		j = (8 - i);
		while(j-- > 0)
			ft_putchar('0');
		while (i > 0)
			ft_putchar(hex[add[--i]]);
	}
	ft_putchar(':');
	ft_putchar(' ');
}


void	ft_print_hex(int i, unsigned int size, unsigned char *p, char *hex)
{
	unsigned int	j;

	j = 0;
	while ((j < 16) && (i + j < size))
	{
		ft_putchar((char)hex[(*(p + i + j) / 16) % 16]);
		ft_putchar((char)hex[*(p + i + j) % 16]);
		if (j % 2)										
			ft_putchar(' ');
		j++;
	}
	while (j < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
}


 void	ft_print_char(int i, unsigned int size, unsigned char *p)
 {	
	unsigned int	j;

	j = 0;
	while ((j < 16) && (i + j < size))
	{
		if (*(p + i + j) >= 32 && *(p + i + j) <= 126)
			ft_putchar((char)*(p + i + j));
		else
			ft_putchar('.');
		j++;
	}
 }


void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*p;
	char			*hex;

	i = 0;
	p = (unsigned char *)addr;
	hex = "0123456789abcdef";
	while (i < size)
	{
		ft_print_address(i, hex);
		ft_print_hex(i, size, p, hex);
		ft_print_char(i, size, p);
		ft_putchar('\n');
		i += 16;
	}
	return (addr + i);
}


/* ************************************************************************** */
/* ************************************************************************** */


