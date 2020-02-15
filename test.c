
# include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	affichage(char **tab)
{
	int i;
	int j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ft_putchar(tab[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}


int	check_line(char **tab, char nb, int x)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (tab[x][i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_column(char **tab, char nb, int y)
{
	int	i;

	i = 1;
	while (i <= 9)
	{
		if (tab[i][y] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_block(char **tab, int x, int y, char nb)
{
	int i;
	int j;

	i = -1;
	if (x <= 3)
		x = 1;
	else if (x <= 6)
		x = 4;
	else if (x <= 9)
		x = 7;
	y = y - (y % 3);
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (tab[x][y] == nb)
				return (0);
			y++;
		}
		y = y - 3;
		x++;
	}
	return (1);
}

int	check_grille(char **tab, int n)
{
	int i;
	int j;

	i = 0;
	if (n == 10)
	{
		while (++i <= 9)
		{
			j = 0;
			while (tab[i][j])
			{
				if ((tab[i][j] < 48 || tab[i][j] > 57) && tab[i][j] != 46)
					return (0);
				j++;
			}
			if (j != 9)
				return (0);
		}
		return (1);
	}
	else
		return (0);
}



int	sudoku(char **tab, int position)
{
	int		x;
	int		y;
	char	nb;

	nb = '0';
	x = position / 9;
	y = position % 9;
	if (position == 90)
		return (1);
	if (tab[x][y] != '.')
		return (sudoku(tab, position + 1));
	while (++nb <= '9')
	{
		if (check_line(tab, nb, x) + check_column(tab, nb, y) == 2)
		{
			if (check_block(tab, x, y, nb) == 1)
			{
				tab[x][y] = nb;
				if (sudoku(tab, position + 1))
					return (1);
			}
		}
	}
	tab[x][y] = '.';
	return (0);
}


int		main(int argc, char **argv)
{
	if (check_grille(argv, argc))
	{
		if (sudoku(argv, 9))
			affichage(argv);
		else
		{
			ft_putstr("Erreur");
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putstr("Erreur");
		ft_putchar('\n');
	}
	return (0);
}
