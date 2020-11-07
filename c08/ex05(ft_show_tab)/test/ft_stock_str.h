/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 13:36:28 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

typedef	struct		s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}					t_stock_str;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);

void				ft_show_tab(struct s_stock_str *par);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);

#endif