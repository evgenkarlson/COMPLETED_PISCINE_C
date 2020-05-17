/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H
# include <stdlib.h>

typedef	struct		s_stock_par
{
	int		size_param;
	char	*str;
	char	*copy;
	char	**tab;
}					t_stock_par;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
int					ft_isspace(char c);
int					ft_wordcount(char *str);
int					ft_wordlen(char *str);

void				ft_show_tab(t_stock_par *par);
char				**ft_split_whitespaces(char *str);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);

#endif