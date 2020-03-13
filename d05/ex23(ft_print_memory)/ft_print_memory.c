/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
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

• Create a function that displays the memory area onscreen.
• The display of this memory area should be split into three columns :
	◦ The hexadecimal address of the first line’s first character ;
	◦ The content in hexadecimal ;
	◦ The content in printable characters.
• If a character is non-printable, it’ll be replaced by a dot.
• Each line should handle sixteen characters.
• If size equals to 0, nothing should be displayed.

• Создать функцию, которая отображает область памяти на экране.
• Отображение этой области памяти должно быть разбито на три столбца:
	◦ Шестнадцатеричный адрес первого символа первой строки;
	◦ Содержание в шестнадцатеричном формате;
	◦ Содержание печатных символов.
• Если символ недоступен для печати, он будет заменен точкой.
• Каждая строка должна содержать шестнадцать символов.
• Если размер равен 0, ничего не должно отображаться.

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void		ft_putchar(char c);


/* ************************************************************************** */


static void	print_hex(int i, unsigned int size, unsigned char *p)
{
	char			*str;
	unsigned int	j;

	j = 0;
	str = "0123456789abcdef";
	while (j < 16 && i + j < size)
	{
		ft_putchar((char)str[(*(p + i + j) / 16) % 16]);
		ft_putchar((char)str[*(p + i + j) % 16]);
		if (j % 2)
			ft_putchar(' ');
		j += 1;
	}
	while (j < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (j % 2)
			ft_putchar(' ');
		j += 1;
	}
}

void		ft_print_memory(void *addr, unsigned int size)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	unsigned char	*p;

	str = "0123456789abcdef";
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_hex(i, size, p);
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (*(p + i + j) >= 32 && *(p + i + j) <= 126)
				ft_putchar((char)*(p + i + j));
			else
				ft_putchar('.');
			j += 1;
		}
		ft_putchar('\n');
		i += 16;
	}
}
