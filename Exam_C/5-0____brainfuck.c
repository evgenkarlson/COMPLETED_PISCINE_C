
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2048

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		find_next(char *str)
{
	int		count;
	int		i;

	i = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] == '[')
			count++;
		else if (str[i] == ']')
		{
			if (count == 0)
				return (i);
			else
				count--;
		}
		i++;
	}
	return (0);
}

int		find_previous(char *str)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (str[i])
	{
		if (str[i] == ']')
			count++;
		else if (str[i] == '[')
		{
			if (count == 0)
				return (i);
			else
				count--;
		}
		i--;
	}
	return (0);
}

int		brainfuck(char *str)
{
	char	*ptr;
	int		c;
	int		p;

	if (!(ptr = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	p = 0;
	while (p <= BUFF_SIZE)
		ptr[p++] = '\0';
	p = 0;
	c = 0;
	while (str[c])
	{
		if (str[c] == '>')
			p++;
		else if (str[c] == '<')
			p--;
		else if (str[c] == '+')
			ptr[p]++;
		else if (str[c] == '-')
			ptr[p]--;
		else if (str[c] == '.')
			ft_putchar(ptr[p]);
		if ((str[c] == '[') && !ptr[p])
			c += find_next(str + c);
		else if ((str[c] == ']') && ptr[p])
			c += find_previous(str + c);
		else
			c++;
	}
	free(ptr);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		brainfuck(av[1]);
	else
		ft_putchar('\n');
	return (0);
}
