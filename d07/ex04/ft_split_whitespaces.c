/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
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

• Создать функцию, которая разбивает строку символов на слова.

• Разделителями являются пробелы, табуляции и разрывы строк.

• Эта функция возвращает массив, в котором каждое поле содержит адрес строки 
  символов, представленный словом. Последний элемент этого массива должен быть 
  равен 0, чтобы подчеркнуть конец массива.

• В вашем массиве не может быть пустых строк. Сделайте необходимые выводы.
• Данная строка не может быть изменена.

• Вот как это должно быть прототипировано:

	char **ft_split_whitespaces(char *str);

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int		ft_is_space(char c)
{
	if((c == ' ' || c == '\t' || c == '\n'))
		return (1);
	return(0);
}

int		ft_num_words(char *str)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (!(words) && !(ft_is_space(str[i])))
			words++;
		else if (ft_is_space(str[i - 1]) && !(ft_is_space(str[i])))
			words++;
		i++;
	}
	return (words);
}

char	*createword(char *str, int i, int j)
{
	char	*word;
	int		o;

	o = 0;
	if ((word = (char*)malloc(sizeof(char) * (j - i + 1))) == ((void *)0))
		return ((void *)0);
	while (i < j)
	{
		word[o] = str[i];
		i++;
		o++;
	}
	word[o] = '\0';
	return (word);
}

char	**ft_split_whitespaces(char *str)
{
	char	**arr;
	int		index;
	int		i;
	int		j;
	int 	words;

	words = ft_num_words(str);
	i = 0;
	j = 0;
	index = 0;
	if (words)
	{
		if ((arr = (char**)malloc(sizeof(char*) * (words + 1))) == ((void *)0))
			return ((void *)0);
		while (index < words)
		{
			while (ft_is_space(str[i]) && str[i])
				i++;
			j = i;
			while (!(ft_is_space(str[j]))  && str[j])
				j++;
			arr[index] = createword(str, i, j);
			i = j + 1;
			index++;
		}
	}
	else
		arr = (char**)malloc(sizeof(char*));
	arr[index] = 0;
	return (arr);
}

/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_is_space(char c)
{
	if((c == ' ' || c == '\t' || c == '\n'))
		return (1);
	return(0);
}

int		ft_wordcount(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!(ft_is_space(str[i])))
			words++;
		while (ft_is_space(str[i + 1]) && !(ft_is_space(str[i])))
			i++;
		i++;
	}
	return (words);
}

static int	ft_wordlen(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (ft_is_space(str[i]))
		i++;
	while (str[i] && !(ft_is_space(str[i])))
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = 0;
	k = 0;
	if (!str || (((arr = (char **)malloc(sizeof(char*) * (ft_wordcount(str) + 1)))) == ((void *)0)))
		return ((void*)0);
	while (i < ft_wordcount(str))
	{
		if ((arr[i] = (char *)malloc(sizeof(char) * (ft_wordlen(&str[k]) + 1))) == ((void *)0))
			return ((void*)0);
		j = 0;
		while (ft_is_space(str[k]))
			k++;
		while (str[k] && !(ft_is_space(str[k])))
			arr[i][j++] = str[k++];
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = ((void*)0);
	return (arr);
}

/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */




#include <stdlib.h>

int		ft_nb_words(char *str)
{
	int i;
	int sym;
	int count;

	i = 0;
	sym = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
		{
			i++;
			sym = 1;
		}
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
		{
			count += (sym == 1) ? 1 : 0;
			sym = 0;
			i++;
		}
	}
	return (count);
}

int		ft_ln_w(char *str, int i)
{
	int count;

	count = 0;
	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split_whitespaces(char *str)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((res = malloc(sizeof(char*) * (ft_nb_words(str) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while ((str[i] == '\t' || str[i] == ' ' || str[i] == '\n') && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if ((res[j] = malloc(sizeof(char) * ft_ln_w(str, i) + 1)) == NULL)
				return (NULL);
			while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
				res[j][k++] = str[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#define IS_SPACE(c) (((c == ' ' || c == '\t' || c == '\n') ? 1 : 0))

int		g_words = 0;

int		calc_numberofwords(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!(g_words) && (!(IS_SPACE(str[i]))))
			g_words++;
		else if (IS_SPACE(str[i - 1]) && !(IS_SPACE(str[i])))
			g_words++;
		i++;
	}
	if (g_words)
		return (1);
	else
		return (0);
}

char	*createword(char *str, int i, int j)
{
	char	*word;
	int		o;

	o = 0;
	word = (char*)malloc(sizeof(char) * (j - i + 1));
	while (i < j)
	{
		word[o] = str[i];
		i++;
		o++;
	}
	word[o] = '\0';
	return (word);
}

int		g_j = 0;
int		g_i = 0;

char	**ft_split_whitespaces(char *str)
{
	char	**arr;
	int		index;

	index = 0;
	if (calc_numberofwords(str))
	{
		arr = (char**)malloc(sizeof(char*) * (g_words + 1));
		while (index < g_words)
		{
			while (IS_SPACE(str[g_i]) && (str[g_i] != '\0'))
				g_i++;
			g_j = g_i;
			while (!(IS_SPACE(str[g_j])) && (str[g_j] != '\0'))
				g_j++;
			arr[index] = createword(str, g_i, g_j);
			g_i = g_j + 1;
			index++;
		}
	}
	else
		arr = (char**)malloc(sizeof(char*));
	arr[index] = 0;
	return (arr);
}