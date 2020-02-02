/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/22 22:20:00 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/24 22:13:31 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	rotate_maj(char c)
{
	c = c - 65;
	c = ((c + 42) % 26);
	c = c + 65;
	return (c);
}

char	rotate_min(char c)
{
	c = c - 97;
	c = ((c + 42) % 26);
	c = c + 97;
	return (c);
}

char	rotate(char c)
{
	if (c >= 65 && c <= 90)
		return (rotate_maj(c));
	else if (c >= 97 && c <= 122)
		return (rotate_min(c));
	else
		return (c);
}

char	*ft_rot42(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = rotate(str[i]);
		i++;
	}
	return (str);
}

int	main()
{
	char	tab[] = "sebastien";
	printf("%s", ft_rot42(tab));
	return 0;
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((int)str[i] < 91)
		{
			if ((int)str[i] >= 75)
				str[i] = str[i] - 10;
			else
				str[i] = str[i] + 16;
		}
		else
		{
			if ((int)str[i] >= 107)
				str[i] = str[i] - 10;
			else
				str[i] = str[i] + 16;
		}
		i++;
	}
	return (str);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



char	*ft_rot42(char *str)
{
	int		i;
	int		y;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		y = 0;
		while (y < 16)
		{
			c = str[i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				if (str[i] == 'z')
					str[i] = 'a';
				else if (str[i] == 'Z')
					str[i] = 'A';
				else
					str[i]++;
			}
			y++;
		}
		i++;
	}
	return (str);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */




/*
** Instead of rotating 13, as ROT13 does (because there is 26 characters
** in the latin alphabet), we do a 42 rotation to make ROT42. This way, we
** substract 26 (all the letters in the alphabet) to 42, to make the actual
** rotation, which is 16 (the first value, from the starting point, which is
** A). Now, we need to find the number that completes the alphabet, from 16,
** which is 10 (26 - 16 = 10). This way, we can rotate successfully. :D
** This link helped me a lot:
** http://stackoverflow.com/questions/13520067/about-rot13-implementation
*/

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'J') ||
		(str[i] >= 'a' && str[i] <= 'j'))
			str[i] = str[i] + 16;
		else if ((str[i] >= 'K' && str[i] <= 'Z') ||
		(str[i] >= 'k' && str[i] <= 'z'))
			str[i] = str[i] - 10;
		else
			str[i];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
