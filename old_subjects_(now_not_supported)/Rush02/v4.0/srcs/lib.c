#include "ft_rush.h"

void	ft_print_error(int n)
{
	write(1, "aucune\n", n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar((char)nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int		ft_count_rows(char *input)
{
	int rows;

	rows = 0;
	while (*input)
	{
		if (*input == '\n')
			rows++;
		input++;
	}
	return (rows);
}

int		ft_count_cols(char *input)
{
	int cols;

	cols = 0;
	while (*input != '\n' && *input)
	{
		input++;
		cols++;
	}
	return (cols);
}

int		ft_strings_equal(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	if (*str1 || *str2)
		return (0);
	return (1);
}

int		ft_is_rush_input_valid(char *input, int rows, int cols)
{
	int row;
	int col;

	row = 0;
	while (*input)
	{
		col = 0;
		while (col++ < cols && *input)
			input++;
		if (*input != '\n')
		{
			ft_print_error(7);
			return (0);
		}
		row++;
		input++;
	}
	if (row < rows)
	{
		ft_print_error(7);
		return (0);
	}
	return (1);
}