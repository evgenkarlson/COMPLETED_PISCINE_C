/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schapuis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/22 12:47:20 by schapuis          #+#    #+#             */
/*   Updated: 2013/08/22 14:56:36 by schapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>


int		calc_nb_words(char *str, int *size_word)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			word++;
		while (str[i] != ' ')
		{
			size_word[word - 1] = size_word[word - 1] + 1;
			i++;
		}
		while (str[i] == ' ')
			i++;
	}
	return (word);
}

void	ft_split_whitespaces(char *str)
{
	int		nb_words;
	int		tab[10];
	char	*temp;
	char	**string;
	int		i;

	i = 0;
	nb_words = calc_nb_words(str, tab);
	*string = (char*)malloc(sizeof(**string) * (nb_words + 1));
	while (i < nb_words)
	{
		string[i] = (char*)malloc(sizeof(*temp) * (tab[i] + 1));
		i++;
	}
}

int	main()
{
	ft_split_whitespaces(" sebas   chapuis wuid ");
	return 0;
}



/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

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

static int	ft_wordcount(char *s, char c)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != ' ' && s[i] != '\n')
			w += 1;
		while (s[i + 1] && s[i] != '\t' && s[i] != ' ' && s[i] != '\n')
			i += 1;
		i += 1;
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
