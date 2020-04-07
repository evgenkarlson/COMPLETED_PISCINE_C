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

• It should return addr.
• Функция должна вернуть адрес.


• Example(Пример):

guilla_i@seattle $> ./ft_print_memory
00000000: 5361 6c75 7420 6c65 7320 616d 696e 6368 Salut les aminch
00000010: 6573 2063 2765 7374 2063 6f6f 6c20 7368 es c'est cool sh
00000020: 6f77 206d 656d 206f 6e20 6661 6974 2064 ow mem on fait d
00000030: 6520 7472 7563 2074 6572 7269 626c 6500 e truc terrible.
00000040: 2e00 0102 0304 0506 0708 090e 0f1b 7f   ...............
guilla_i@seattle $> ./ft_print_memory | cat -te
00000000: 5361 6c75 7420 6c65 7320 616d 696e 6368 Salut les aminch$
00000010: 6573 2063 2765 7374 2063 6f6f 6c20 7368 es c'est cool sh$
00000020: 6f77 206d 656d 206f 6e20 6661 6974 2064 ow mem on fait d$
00000030: 6520 7472 7563 2074 6572 7269 626c 6500 e truc terrible.$
00000040: 2e00 0102 0304 0506 0708 090e 0f1b 7f   ...............$
guilla_i@seattle $>


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void		ft_putchar(char c);


/* ************************************************************************** */



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
		while(j-- > 0)
			ft_putchar('0');
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

void	ft_print_memory(void *addr, unsigned int size)
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
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void		ft_putchar(char c);


/* ************************************************************************** */


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
		while(j-- > 0)
			ft_putchar('0');
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
}


 void	ft_print_char(int i, unsigned int size, unsigned char *p)
 {	
	unsigned int	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (*(p + i + j) >= 32 && *(p + i + j) <= 126)
			ft_putchar((char)*(p + i + j));
		else
			ft_putchar('.');
		j++;
	}
 }


void	ft_print_memory(void *addr, unsigned int size)
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
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


