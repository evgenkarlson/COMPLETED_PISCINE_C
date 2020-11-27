/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 21:14:20 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/21 21:14:21 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


• The aim of this function is to count the amount of times two strings match.
• When we have two or more stars, multiple string combinations can be suitable.
• nmatch calculates the total amount of combinations.
• Here are some examples :
	"abcbd" & "*b*" match twice : ("a","cbd") and ("abc", "d")
	"abc" & "a**" match 3 times : (nothing,"bc"), ("b", "c") and ("bc", nothing)

• nmatch returns the number of combinations that match.


• Цель этой функции - подсчитать количество совпадений двух строк.
• Когда у нас две или более звездочек, могут подойти несколько комбинаций струн.
• nmatch вычисляет общее количество комбинаций.
• Вот несколько примеров :
	"abcbd" и "* b *" совпадают дважды: ("a", "cbd") и ("abc", "d")
	«abc» и «a **» совпадают 3 раза: (ничего, «bc»), («b», «c») и («bc», ничего)

• nmatch возвращает количество совпадающих комбинаций.


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		nmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s2 == '*')
	{
		if (!*s1)
			return (nmatch(s1, s2 + 1));
		else
			return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	}
	else if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	else
		return (0);
}





/* ************************************************************************** */
/* ******************************_OR_THAT_*********************************** */
/* ************************************************************************** */


int		nmatch(char *s1, char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2));
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	if (*s1 == '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1));
	return (0);
}

/* ************************************************************************** */
/* ******************************_OR_THAT_*********************************** */
/* ************************************************************************** */



unsigned int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len) != '\0')
	{
		len++;
	}
	return (len);
}

unsigned int	star_count(char *str)
{
	int n;

	n = 0;
	while (*str)
		if (*str++ == '*')
			n++;
	return (n);
}

int				recur(char *s1, char *s2, unsigned int star_len)
{
	unsigned int i;
	unsigned int n;

	n = 0;
	while (1)
	{
		if (*s2 == '*')
		{
			i = 0;
			while (i++ <= star_len)
				n += recur(s1 + i - 1, s2 + 1, star_len - i + 1);
			return (n);
		}
		if (!*s1)
		{
			if (!*s2)
				n++;
			return (n);
		}
		if (!*s2)
			return (n);
		if (*s1++ != *s2++)
			return (n);
	}
}

int				nmatch(char *s1, char *s2)
{
	return (recur(s1, s2, ft_strlen(s1) - ft_strlen(s2) + star_count(s2)));
}
