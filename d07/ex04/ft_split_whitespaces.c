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

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/*int   ft_wordcount(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}
*/
int		ft_wordcount(char *str)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_isspace(*str)))
			words++;
		else if (ft_isspace(*(str - 1)) && !(ft_isspace(*str)))
			words++;
		str++;
	}
	return (words);
}

int		ft_wordlen(char *str)
{
	int		len;

	len = 0;
	while (ft_isspace(*str))
		str++;
	while (*str && !(ft_isspace(*str)))
	{
		str++;
		len++;
	}
	return (len);
}

char	**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	char	**arr;
	int		words;

	words = ft_wordcount(str);
	i = 0;
	if (!str || (((arr = (char **)malloc(sizeof(char*) * (words + 1)))) == ((void *)0)))
		return ((void*)0);
	while (i < words)
	{
		if ((arr[i] = (char *)malloc(sizeof(char) * (ft_wordlen(str) + 1))) == ((void *)0))
			return ((void*)0);
		j = 0;
		while (ft_isspace(*str))
			str++;
		while (*str && !(ft_isspace(*str)))
			arr[i][j++] = *str++;
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

int   ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

/*int   ft_wordcount(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}
*/
int		ft_wordcount(char *str)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_isspace(*str)))
			words++;
		else if (ft_isspace(*(str - 1)) && !(ft_isspace(*str)))
			words++;
		str++;
	}
	return (words);
}

char  *malloc_word(char *str)
{
	char *word;
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_whitespaces(char *str)
{
	int i;
	char **arr;

	arr = (char **)malloc(sizeof(char *) * (ft_wordcount(str) + 1));
	i = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			arr[i] = malloc_word(str);
			i++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	arr[i] = ((void *)0);
	return (arr);
}


/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#define IS_SPACE(c) (((c == ' ' || c == '\t' || c == '\n') ? 1 : 0))

/*int   ft_wordcount(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (IS_SPACE(*str)))
			str++;
		if (*str && !(IS_SPACE(*str)))
		{
			count++;
			while (*str && !(IS_SPACE(*str)))
				str++;
		}
	}
	return (count);
}
*/
int   ft_wordcount(char *str)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(IS_SPACE(*str)))
			words++;
		else if (IS_SPACE(*(str - 1)) && !(IS_SPACE(*str)))
			words++;
		str++;
	}
	return (words);
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

char	**ft_split_whitespaces(char *str)
{
	char	**arr;
	int		index;
	int		j;
	int		i;
	int		words;

	words = ft_wordcount(str);
	j = 0;
	i = 0;
	index = 0;
	if (words)
	{
		arr = (char**)malloc(sizeof(char*) * (words + 1));
		while (index < words)
		{
			while (IS_SPACE(str[i]) && (str[i]))
				i++;
			j = i;
			while (!(IS_SPACE(str[j])) && (str[j]))
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



#include <stdlib.h>

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/*int   ft_wordcount(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}
*/
int		ft_wordcount(char *str)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_isspace(*str)))
			words++;
		else if (ft_isspace(*(str - 1)) && !(ft_isspace(*str)))
			words++;
		str++;
	}
	return (words);
}

int		ft_len_word(char *str, int i)
{
	int count;

	count = 0;
	while (!(ft_isspace(str[i])) && str[i])
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
	if ((res = malloc(sizeof(char*) * (ft_wordcount(str) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while (ft_isspace(str[i]) && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if ((res[j] = malloc(sizeof(char) * ft_len_word(str, i) + 1)) == NULL)
				return (NULL);
			while (ft_isspace(str[i]) && str[i])
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