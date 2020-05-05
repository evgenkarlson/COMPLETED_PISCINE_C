/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
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

• Создать функцию, которая преобразует аргументы, заданные в командной строке, в
  одну строку символов. Эти аргументы должны быть разделены "\ n".

• Вот как это должно быть прототипировано:

	char *ft_concat_params(int argc, char **argv);

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (dest[i])
		i++;
	while (src[x])
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	char	*str;
	int		length;

	i = 1;
	length = 0;
	while (i < argc)
	{
		length += ft_strlen(argv[i]);
		i++;
	}
	if ((str = (char *)malloc(sizeof(char) * (length + argc))) == ((void *)0))
		return ((void *)0);
	i = 1;
	while (i < argc)
	{
		ft_strcat(str, argv[i]);
		ft_strcat(str, "\n");
		i++;
	}
	ft_strcat(str, "\0");
	return (str);
}



/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */




#include <stdlib.h>


char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		z;
	char	*str;

	i = 1;
	z = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			j++;
		z += j;
		i++;
	}
	if ((str = (char *)malloc(sizeof(char) * (z + argc))) == ((void *)0))
		return ((void *)0);
	i = 0;
	j = 1;
	z = 0;
	while (j < argc)
	{
		z = 0;
		while (argv[j][z])
		{
			str[i] = argv[j][z];
			z++;
			i++;
		}
		str[i] = '\n';
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}




/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		calc_size_params(int argc, char **argv)
{
	int	size_argv;
	int	i;
	int	z;

	i = 1;
	z = 0;
	size_argv = 0;
	while (i < argc)
	{
		while (argv[i][z])
			z++;
		size_argv += z;
		z = 0;
		i++;
	}
	return (size_argv);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (dest[i])
		i++;
	while (src[x])
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int	i;
	char	*str;
	int		length;

	i = 0;
	length = calc_size_params(argc, argv);
	str = (char*)malloc(sizeof(*str) * (length + argc));
	i = 1;
	while (i < argc)
	{
		ft_strcat(str, argv[i]);
		ft_strcat(str, "\n");
		i++;
	}
	ft_strcat(str, "\0");
	return (str);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */