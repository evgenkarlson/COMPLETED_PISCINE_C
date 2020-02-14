/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_alert(void)
{
	write(1, "Alert !!!\n", 10);
}

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	find_alert(char *str)
{
	if (ft_strcmp(str, "president") == 0)
		write_alert();
	if (ft_strcmp(str, "attentat") == 0)
		write_alert();
	if (ft_strcmp(str, "bauer") == 0)
		write_alert();
}

void	to_minuscule(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	temp[1000];
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < argc)
	{
		j = 0;
		k = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
			{
				temp[k] = argv[i][j];
				k++;
			}
			j++;
		}
		temp[j] = '\0';
		to_minuscule(temp);
		find_alert(temp);
		i++;
	}
	return (0);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */




char	*jp_ltrim(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

char	*jp_rtrim(char *str)
{
	char	*e;
	int		i;

	i = 0;
	while (str[i])
		i++;
	e = str + i;
	while (*--e == ' ')
		;
	*(e + 1) = '\0';
	return (str);
}

char	*jp_trim(char *str)
{
	return (jp_rtrim(jp_ltrim(str)));
}

int		jp_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			s1[i] = s1[i] - 'A' + 'a';
		i++;
	}
	while (*s1++ == *s2++)
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
	return (*--s1 - *--s2);
}

int		main(int argc, char **argv)
{
	int i;
	int a;

	a = 0;
	i = 1;
	if (argc > 1)
		while (i < argc)
		{
			if (jp_strcmp(jp_trim(argv[i]), "president") == 0)
				a = 1;
			else if (jp_strcmp(jp_trim(argv[i]), "attack") == 0)
				a = 1;
			else if (jp_strcmp(jp_trim(argv[i]), "powers") == 0)
				a = 1;
			i++;
		}
	if (a == 1)
		write(1, "Alert!!!\n", 9);
	return (0);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	putalert(void)
{
	int			i;
	char		c;
	const char	*str = "Alert!!!";

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	c = '\n';
	write(1, &c, 1);
}

char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
		{
			c = str[i] + 32;
			str[i] = c;
		}
		i++;
	}
	return (str);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (s2[x] == 32)
		x++;
	while (s1[i] == s2[x])
	{
		if (s1[i] == '\0' && s2[x] == '\0')
			return (1);
		i++;
		x++;
		if (s1[i] == '\0' && s2[x] == 32)
			return (1);
	}
	return (0);
}

int		checkword(char *str)
{
	if (ft_strcmp("president", ft_strlowcase(str)) || ft_strcmp("attack",
				ft_strlowcase(str)) || ft_strcmp("powers", ft_strlowcase(str)))
	{
		putalert();
		return (1);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int	i;
	int done;

	if (argc == 1)
		return (0);
	done = 0;
	i = 1;
	while (i < argc && !done)
	{
		if (checkword(argv[i]))
			done = 1;
		i++;
	}
	return (0);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */




int		ft_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++)
		if ((*s1 == '\0' && *s2 == '\0') || (*s1 == '\0' && *s2 == ' '))
			return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_escape_space(char *str)
{
	int i;

	while (str[0] != '\0' && str[0] == ' ')
	{
		i = 0;
		while (str[i] != '\0')
		{
			str[i] = str[i + 1];
			i++;
		}
	}
	return (str);
}

int		main(int argc, char **argv)
{
	int i;
	int error;

	i = 1;
	error = 0;
	while (i < argc && error == 0)
	{
		if (ft_strcmp("president", ft_strlowcase(ft_escape_space(argv[i]))))
			error = 1;
		if (ft_strcmp("attack", ft_strlowcase(ft_escape_space(argv[i]))))
			error = 1;
		if (ft_strcmp("powers", ft_strlowcase(ft_escape_space(argv[i]))))
			error = 1;
		i++;
	}
	if (error)
		write(1, "Alert!!!\n", 9);
	return (0);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



int		main(int argc, char *argv[])
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (--argc)
	{
		if (argv[j][i] == ("president" || "attack" || "powers"))
			write(1, "Alert!!\n", 8);
		i = 0;
		j += 1;
	}
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
