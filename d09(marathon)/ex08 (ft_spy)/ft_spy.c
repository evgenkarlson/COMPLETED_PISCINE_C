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


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************
 *
 *
 *	• Напишите файл ft_spy.c, который будет покупать на стандартном выходе -
 *	Alert !!! с последующим переводом строки, если один из аргументов, переданных 
 *	в параметре, соответствует словам президент, атака или полномочия.
 *
 *
 *	• Очевидно, ваш файл ft_spy.c должен содержать main.
 *------------------------------------------------------------------------------
 *  	$> $./ft_spy "I" "will" "kill" "Austin" "Powers"
 *  	Alert!!!
 *  	$> $./ft_spy "Hello" "I" "want" "a" "4" "cheese" "pizza"
 *  	$> $./ft_spy "The attack" "will" "start" "soon"
 *  	$> $./ft_spy "an" "attack" "will" "start" "soon"
 *  	Alert!!!
 *  	$>
 *------------------------------------------------------------------------------
 *
 *
 *	• Обратите внимание на несколько тонкостей:
 *------------------------------------------------------------------------------
 *  	$> $./ft_spy "I" "will" "kill" "Nigel" "PoWeRs"
 *  	Alert!!!
 *  	$> $./ft_spy "   the   " "  president    " "must" "die   "
 *  	Alert!!!
 *  	$> $./ft_spy "   the""omnipresident""must""eat  "
 *  	$>
 *------------------------------------------------------------------------------
 *
 *
 *	• Почему бы не воспользоваться этим упражнением для создания многократно 
 *  используемых модульных функций в вашей библиотеке?
 *
 *
 *
 * ##########################################################################
 *	P.S. Нас просят создать программу которая в массиве строк переданых с
 *	аргументами будет искать слова при нахождении которых будет напечатано "Alert!!!"
 * ##########################################################################
 *
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

void	ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}


void	ft_find_first_word(char *str, char *temp)
{
	int	j;
	int k;

	j = 0;
	k = 0;
	while (str[j])
	{
		if (str[j] != ' ')
			temp[k++] = str[j];
		j++;

	}
	temp[j] = '\0';
}

void	ft_find_alert(int argc, char **argv, char **to_find)
{
	char	temp[20];
	int		i;
	int		k;

	i = 1;
	while (i < argc)
	{
		ft_find_first_word(argv[i], temp);
		ft_strlowcase(temp);
		k = 0;
		while(to_find[k])
		{
			if (ft_strcmp(temp, to_find[k]) == 0)
				write(1, "Alert !!!\n", 10);
			k++;
		}
		i++;
	}
}


int		main(int argc, char **argv)
{
	char	*array[4] = {"president","attack","powers"};

	if (argc > 1)
		ft_find_alert(argc, argv, array);
	return (0);
}





/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

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

#include <unistd.h>

void	putalert(void)
{
	write(1, "Alert !!!\n", 10);
}

char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
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

#include <unistd.h>

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
