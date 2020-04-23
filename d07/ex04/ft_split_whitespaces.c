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
	int	g_words;

	g_words = 0;
	i = 0;
	while (str[i])
	{
		if (!(g_words) && !(ft_is_space(str[i])))
			g_words++;
		else if (ft_is_space(str[i - 1]) && !(ft_is_space(str[i])))
			g_words++;
		i++;
	}
	return (g_words);
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
	int		g_j;
	int		g_i;
	int 	g_words;

	g_words = ft_num_words(str);
	g_i = 0;
	g_j = 0;
	index = 0;
	if (g_words)
	{
		if ((arr = (char**)malloc(sizeof(char*) * (g_words + 1))) == ((void *)0))
			return ((void *)0);
		while (index < g_words)
		{
			while (ft_is_space(str[g_i]) && str[g_i])
				g_i++;
			g_j = g_i;
			while (!(ft_is_space(str[g_j]))  && str[g_j])
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


/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

#include <stdio.h>
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

/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_wordcount(char *s, char c)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != ' ' && s[i] != '\n')
			w++;
		while (s[i + 1] && s[i] != '\t' && s[i] != ' ' && s[i] != '\n')
			i++;
		i++;
	}
	return (w);
}

static int	ft_wordlen(char *s)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i += 1;
	while (s[i] && s[i] != '\t' && s[i] != ' ' && s[i++] != '\n')
		len += 1;
	return (len);
}

char		**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**w;

	i = 0;
	k = 0;
	if (!str || !(w = (char **)malloc(sizeof(char*) * (ft_wordcount(str) + 1))))
		return (NULL);
	while (i < ft_wordcount(str))
	{
		if (!(w[i] = (char *)malloc(sizeof(char) * (ft_wordlen(&str[k]) + 1))))
			return (NULL);
		j = 0;
		while (str[k] == '\t' || str[k] == ' ' || str[k] == '\n')
			k += 1;
		while (str[k] && str[k] != '\t' && str[k] != ' ' && str[k] != '\n')
			w[i][j++] = str[k++];
		w[i][j] = '\0';
		i += 1;
	}
	w[i] = NULL;
	return (w);
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