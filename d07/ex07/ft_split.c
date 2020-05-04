/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
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

• Создайте функцию, которая разрезает одну строку символов в используя значения
  другой строки символов.
• Используйте каждый символ из строкового набора символов в качестве
  разделителя.
• Функция возвращает массив, с блоками содержащими адреса строк со словом
  между двумя разделителями. Последний элемент этого массива должен быть равен 0,
  чтобы указать конец массива.
• В вашем массиве не может быть пустых строк. Сделайте свои выводы соответственно.
• Строка, указанная в качестве аргумента, не подлежит изменению.
• Вот как это должно быть прототипировано:

	char  **ft_split(char *str, char *charset);

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strchar(char to_find, char *str)
{
	while (*str)
		if (to_find == *str++)
			return (1);
	return (0);
}

/* 
int		ft_wordcount(char *str, char *spacechar)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_strchar(*str, spacechar))
			str++;
		if (*str && !ft_strchar(*str, spacechar))
		{
			count++;
			while (*str && !ft_strchar(*str, spacechar))
				str++;
		}
	}
	return (count);
}
*/

int		ft_wordcount(char *str, char *spacechar)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_strchar(*str, spacechar)))
			words++;
		else if (ft_strchar(*(str - 1), spacechar) && !(ft_strchar(*str, spacechar)))
			words++;
		str++;
	}
	return (words);
}

int		ft_wordlen(char *str, char *spacechar)
{
	int		len;

	len = 0;
	while (ft_strchar(*str, spacechar))
		str++;
	while (*str && !(ft_strchar(*str, spacechar)))
	{
		str++;
		len++;
	}
	return (len);
}

char	**ft_split_whitespaces(char *str, char *spacechar)
{
	int		i;
	int		j;
	char	**arr;
	int		words;

	words = ft_wordcount(str, spacechar);
	i = 0;
	if (!str || (((arr = (char **)malloc(sizeof(char*) * (words + 1)))) == ((void *)0)))
		return ((void*)0);
	while (i < words)
	{
		if ((arr[i] = (char *)malloc(sizeof(char) * (ft_wordlen(str, spacechar) + 1))) == ((void *)0))
			return ((void*)0);
		j = 0;
		while (ft_strchar(*str, spacechar))
			str++;
		while (*str && !(ft_strchar(*str, spacechar)))
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


int		ft_strchar(char to_find, char *str)
{
	while (*str)
		if (to_find == *str++)
			return (1);
	return (0);
}

/* 
int		ft_wordcount(char *str, char *spacechar)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_strchar(*str, spacechar))
			str++;
		if (*str && !ft_strchar(*str, spacechar))
		{
			count++;
			while (*str && !ft_strchar(*str, spacechar))
				str++;
		}
	}
	return (count);
}
*/

int		ft_wordcount(char *str, char *spacechar)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_strchar(*str, spacechar)))
			words++;
		else if (ft_strchar(*(str - 1), spacechar) && !(ft_strchar(*str, spacechar)))
			words++;
		str++;
	}
	return (words);
}


char  *malloc_word(char *str, char *spacechar)
{
	char *word;
	int	i;

	i = 0;
	while (str[i] && !ft_strchar(str[i], spacechar))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_strchar(str[i], spacechar))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *spacechar)
{
	int i;
	char **arr;

	arr = (char **)malloc(sizeof(char *) * (ft_wordcount(str, spacechar) + 1));
	i = 0;
	while (*str)
	{
		while (*str && ft_strchar(*str, spacechar))
			str++;
		if (*str && !ft_strchar(*str, spacechar))
		{
			arr[i] = malloc_word(str, spacechar);
			i++;
			while (*str && !ft_strchar(*str, spacechar))
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

int		ft_strchar(char to_find, char *str)
{
	while (*str)
		if (to_find == *str++)
			return (1);
	return (0);
}

/*int   ft_wordcount(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (ft_strchar(*str)))
			str++;
		if (*str && !(ft_strchar(*str)))
		{
			count++;
			while (*str && !(ft_strchar(*str)))
				str++;
		}
	}
	return (count);
}
*/
int   ft_wordcount(char *str, char *spacechar)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_strchar(*str, spacechar)))
			words++;
		else if (ft_strchar(*(str - 1), spacechar) && !(ft_strchar(*str, spacechar)))
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

char	**ft_split(char *str, char *spacechar)
{
	char	**arr;
	int		index;
	int		j;
	int		i;
	int		words;

	words = ft_wordcount(str, spacechar);
	j = 0;
	i = 0;
	index = 0;
	if (words)
	{
		arr = (char**)malloc(sizeof(char*) * (words + 1));
		while (index < words)
		{
			while (ft_strchar(str[i], spacechar) && (str[i]))
				i++;
			j = i;
			while (!(ft_strchar(str[j], spacechar)) && (str[j]))
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

int		ft_strchar(char to_find, char *str)
{
	while (*str)
		if (to_find == *str++)
			return (1);
	return (0);
}


/*int   ft_wordcount(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_strchar(*str))
			str++;
		if (*str && !ft_strchar(*str))
		{
			count++;
			while (*str && !ft_strchar(*str))
				str++;
		}
	}
	return (count);
}
*/
int		ft_wordcount(char *str, char *spacechar)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_strchar(*str, spacechar)))
			words++;
		else if (ft_strchar(*(str - 1), spacechar) && !(ft_strchar(*str, spacechar)))
			words++;
		str++;
	}
	return (words);
}

int		ft_len_word(char *str, int i, char *spacechar)
{
	int count;

	count = 0;
	while (!(ft_strchar(str[i], spacechar)) && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *spacechar)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((res = malloc(sizeof(char*) * (ft_wordcount(str, spacechar) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while (ft_strchar(str[i], spacechar) && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if ((res[j] = malloc(sizeof(char) * ft_len_word(str, i, spacechar) + 1)) == NULL)
				return (NULL);
			while (ft_strchar(str[i], spacechar) && str[i])
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