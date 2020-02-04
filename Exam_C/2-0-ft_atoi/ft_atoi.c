/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 22:48:46 by jaleman           #+#    #+#             */
/*   Updated: 2016/09/01 23:07:26 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		ft_atoi(char *str)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str == '\0')
		return (0);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * sign);
}



/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */


int	ft_atoi(char *str)
{
	int	x;
	int total;
	int is_negative;

	is_negative = 0;
	x = 0;
	total = 0;
	while (str[x] == ' ' || str[x] == '\n' || str[x] == '\r' || str[x] == '\f'
			|| str[x] == '\t' || str[x] == '\v' || str[x] == '+')
		x++;
	if (str[x] == '-')
	{
		is_negative = 1;
		x++;
	}
	while (str[x] >= 48 && str[x] <= 57)
	{
		total *= 10;
		total += ((int)str[x] - 48);
		x++;
	}
	if (is_negative)
		return (-total);
	else
		return (total);
}
