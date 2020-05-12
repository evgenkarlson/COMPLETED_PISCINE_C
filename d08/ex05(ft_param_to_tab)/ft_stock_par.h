/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
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


	Allowed functions : ft_split_whitespaces, ft_show_tab, malloc
	Разрешенные функции: ft_split_whitespaces, ft_show_tab, malloc


   **************************************************************************   

	• Create a function that stores the program’s arguments within an array 
	structure and that returns the address of that array’s first box.
	• Создать функцию, которая хранит аргументы программы в структуре массива 
	и возвращает адрес первого блока этого массива.

   **************************************************************************   

	• All elements of the array must be processed, including av[0].
	• Все элементы массива должны быть обработаны, включая av [0].

   **************************************************************************   
	• Here’s how it should be prototyped :
	• Вот как это должно быть прототипировано:

struct s_stock_par *ft_param_to_tab(int ac, char **av);

   **************************************************************************   

	• The structure array should be allocated and its last box shall contain 0 in 
	its str element to point out the end of the array.
	• Массив структуры должен быть размещен, и его последний блок должен содержать 
	0 в своем элементе str, чтобы указать конец массива.

   **************************************************************************   
	• The structure is defined in the ft_stock_par.h file, like this :
	• Структура определяется в файле ft_stock_par.h, как тут:

typedef struct	s_stock_par
{
	int size_param;
	char *str;
	char *copy;
	char **tab;
}				t_stock_par;

		◦ size_param being the length of the argument / ◦ size_param - длина 
		аргумента;

		◦ str being the address of the argument / ◦ str - адрес аргумента;

		◦ copy being the copy of the argument / ◦ копия является копией аргумента;

		◦ tab being the array returned by ft_split_whitespaces. / ◦ tab - массив, 
		возвращаемый ft_split_whitespaces.

   **************************************************************************   

	• We’ll test your function with our ft_split_whitespaces and our ft_show_tab
	(next exercise). Take the appropriate measures for this to work !
	• Мы протестируем вашу функцию с помощью наших ft_split_whitespaces и нашего 
	ft_show_tab (следующее упражнение). Примите соответствующие меры, чтобы это работало!


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

# include <stdlib.h>

typedef	struct	s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}				t_stock_par;

char			**ft_split_whitespaces(char *str);
char			*ft_strdup(char *src);
void			ft_putchar(char c);

#endif


/* ************************************************************************** */
/* ***********************************_ИЛИ_********************************** */
/* ************************************************************************** */


#ifndef __FT_STOCK_PAR_H
# define __FT_STOCK_PAR_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}					t_stock_par;

void				ft_show_tab(t_stock_par *par);
char				**ft_split_whitespaces(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nbr);
int					ft_strlen(char *str);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);
#endif


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
