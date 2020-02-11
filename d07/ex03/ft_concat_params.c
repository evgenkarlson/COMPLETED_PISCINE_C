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

void	write_tab(int argc, char **argv, char *string, int size_params)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 1;
	z = 0;
	while (i < size_params)
	{
		while (j < argc)
		{
			while (argv[j][z])
			{
				string[i] = argv[j][z];
				z++;
				i++;
			}
			string[i] = '\n';
			i++;
			z = 0;
			j++;
		}
	}
	string[i] = '\0';
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*string;
	int		size_params;

	size_params = calc_size_params(argc, argv);
	string = (char*)malloc(sizeof(*string) * (size_params + argc - 1));
	write_tab(argc, argv, string, size_params);
	return (string);
}



/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */


int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (dest[i] != '\0')
		i++;
	while (src[x] != '\0')
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
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 1;
	while (i < argc)
	{
		len += ft_strlen(argv[i]);
		i++;
	}
	str = (char*)malloc(sizeof(char) * (len + argc));
	i = 1;
	while (i < argc)
	{
		ft_strcat(str, argv[i]);
		if (i != argc - 1)
			ft_strcat(str, "\n");
		else
			ft_strcat(str, "\0");
		i++;
	}
	return (str);
}



/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */


int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_strlen_total(int argc, char **argv)
{
	int count;
	int i;

	i = 1;
	count = 0;
	while (i < argc)
	{
		count = count + ft_strlen(argv[i]);
		i++;
	}
	return (count);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*r;
	int		total;
	int		i;
	int		y;
	int		c;

	total = ft_strlen_total(argc, argv) + argc;
	r = (char*)malloc(sizeof(*r) * total);
	i = 1;
	c = 0;
	while (i < argc)
	{
		y = 0;
		while (argv[i][y] != '\0')
		{
			r[c] = argv[i][y];
			c++;
			y++;
		}
		r[c] = '\n';
		c++;
		i++;
	}
	r[c - 1] = '\0';
	return (r);
}




/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */


char		*ft_contact_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 9001)))
		return (NULL);
	k = 0;
	while (k < 9001)
		str[k++] = '\0';
	k = 0;
	i = 1;
	while (--argc)
	{
		j = 0;
		while (argv[i][j])
			str[k++] = argv[i][j++];
		str[k++] = '\n';
		i += 1;
	}
	return (str);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

