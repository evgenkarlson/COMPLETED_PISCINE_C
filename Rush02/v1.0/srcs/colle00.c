/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test-colle-01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 15:43:36 by adespond          #+#    #+#             */
/*   Updated: 2015/09/20 17:31:46 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colle.h"

char	*colle00_0(int x, int y)
{
	char	*colle;
	char	*pattern;

	pattern = "o-o| |o-o";
	colle = generate_colle(x, y, pattern);
	return (colle);
}

char	*colle00_1(int x, int y)
{
	char	*colle;
	char	*pattern;

	pattern = "/*\\* *\\*/";
	colle = generate_colle(x, y, pattern);
	return (colle);
}

char	*colle00_2(int x, int y)
{
	char	*colle;
	char	*pattern;

	pattern = "ABAB BCBC";
	colle = generate_colle(x, y, pattern);
	return (colle);
}

char	*colle00_3(int x, int y)
{
	char	*colle;
	char	*pattern;

	pattern = "ABCB BABC";
	colle = generate_colle(x, y, pattern);
	return (colle);
}

char	*colle00_4(int x, int y)
{
	char	*colle;
	char	*pattern;

	pattern = "ABCB BCBA";
	colle = generate_colle(x, y, pattern);
	return (colle);
}
