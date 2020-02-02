/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 23:27:36 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/20 23:27:37 by jaleman          ###   ########.fr       */
/*                                                                            */
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
