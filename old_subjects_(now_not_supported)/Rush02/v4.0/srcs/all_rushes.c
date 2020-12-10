
#include "ft_rush.h"

char	*ft_rush00(int x, int y)
{
	int c;
	int r;
	int		i;
	char	*result;
	result = (char *)malloc(sizeof(char) * (y * (x + 1) + 1));
	i = 0;
	c = 1;
	r = 0;
	if (x < 1 && y < 1)
		return (0);
	while (r++ <= (y - 1))
	{
		while (c <= x)
		{
			if ((r == 1 || r == y) && (c == 1 || c == x))
				result[i++] = 'o';
			else if ((r > 1 && r < y) && (c > 1 && c < x))
				result[i++] = ' ';
			else if (r == 1 || r == y)
				result[i++] = '-';
			else
				result[i++] = '|';
			++c;
		}
		result[i++] = '\n';
		c = 1;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_rush01(int x, int y)
{
	int c;
	int r;

	int		i;
	char	*result;
	result = (char *)malloc(sizeof(char) * (y * (x + 1) + 1));
	i = 0;

	c = 1;
	r = 0;
	if (x < 1 && y < 1)
		return (0);
	while (r++ <= (y - 1))
	{
		while (c <= x)
		{
			if ((r == 1 && c == 1) || (r == y && c == x && x != 1 && y != 1))
				result[i++] = '/';
			else if (((r == y && c == 1) || (r == 1 && c == x)))
				result[i++] = '\\';
			else if ((r > 1 && r < y) && (c > 1 && c < x))
				result[i++] = ' ';
			else
				result[i++] = '*';
			++c;
		}
		result[i++] = '\n';
		c = 1;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_rush02(int x, int y)
{
	int c;
	int r;
	int		i;
	char	*result;
	result = (char *)malloc(sizeof(char) * (y * (x + 1) + 1));
	i = 0;
	c = 1;
	r = 0;
	if (x < 1 && y < 1)
		return (0);
	while (r++ <= (y - 1))
	{
		while (c <= x)
		{
			if ((r == 1 && c == 1) || (r == 1 && c == x && x != 1))
				result[i++] = 'A';
			else if ((r == y && c == 1) || (r == y && c == x && y != 1))
				result[i++] = 'C';
			else if ((r > 1 && r < y) && (c > 1 && c < x))
				result[i++] = ' ';
			else
				result[i++] = 'B';
			++c;
		}
		result[i++] = '\n';
		c = 1;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_rush03(int x, int y)
{
	int c;
	int r;
	int		i;
	char	*result;
	result = (char *)malloc(sizeof(char) * (y * (x + 1) + 1));
	i = 0;
	c = 1;
	r = 0;
	if (x < 1 && y < 1)
		return (0);
	while (r++ <= (y - 1))
	{
		while (c <= x)
		{
			if ((r == 1 && c == 1) || (r == y && c == 1))
				result[i++] = 'A';
			else if ((r == 1 && c == x) || (r == y && c == x))
				result[i++] = 'C';
			else if ((r > 1 && r < y) && (c > 1 && c < x))
				result[i++] = ' ';
			else
				result[i++] = 'B';
			++c;
		}
		result[i++] = '\n';
		c = 1;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_rush04(int x, int y)
{
	int c;
	int r;
	int		i;
	char	*result;
	result = (char *)malloc(sizeof(char) * (y * (x + 1) + 1));
	i = 0;
	c = 1;
	r = 0;
	if (x < 1 && y < 1)
		return (0);
	while (r++ <= (y - 1))
	{
		while (c <= x)
		{
			if ((r == 1 && c == 1) || (r == y && c == x && x != 1 && y != 1))
				result[i++] = 'A';
			else if (((r == y && c == 1) || (r == 1 && c == x)))
				result[i++] = 'C';
			else if ((r > 1 && r < y) && (c > 1 && c < x))
				result[i++] = ' ';
			else
				result[i++] = 'B';
			++c;
		}
		result[i++] = '\n';
		c = 1;
	}
	result[i] = '\0';
	return (result);
}