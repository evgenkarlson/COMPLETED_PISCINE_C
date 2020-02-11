/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if (!(base %2))
		base = base / 2;
	else
		base = 3 * base + 1;
	return (ft_collatz_conjecture(base) + 1);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if ((base % 2) == 0)
		return (ft_collatz_conjecture(base / 2));
	else
		return (ft_collatz_conjecture(base * 3 + 1));
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if (base % 2 == 0)
		return (1 + ft_collatz_conjecture(base / 2));
	else
		return (1 + ft_collatz_conjecture(base * 3 + 1));
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	else
	{
		if (base % 2)
			base = ft_collatz_conjecture(3 * base + 1) + 1;
		else
			base = ft_collatz_conjecture(base / 2) + 1;
	}
	return (base);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

/*
** The conjecture can be summarized as follows. Take any positive integer n.
** If n is even, divide it by 2 to get n / 2. If n is odd, multiply it
** by 3 and add 1 to obtain 3n + 1. Repeat the process indefinitely.
** The conjecture is that no matter what number you start with,
** you will always eventually reach 1.
** Source: https://en.wikipedia.org/wiki/Collatz_conjecture
**
** https://xkcd.com/710/	   ;)
*/

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if ((base % 2) != 1)
		base = base / 2;
	else
		base = 3 * base + 1;
	return (ft_collatz_conjecture(base) + 1);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
