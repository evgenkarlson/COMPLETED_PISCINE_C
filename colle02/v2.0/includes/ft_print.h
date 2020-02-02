/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbufnoir <rbufnoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 22:26:02 by rbufnoir          #+#    #+#             */
/*   Updated: 2014/07/20 22:55:41 by rbufnoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JP_PRINT_H
# define JP_PRINT_H

# include <unistd.h>

void	jp_putchar(char c);
void	jp_putstr(char *str);
void	jp_show(int nb, int arg1, int arg2, int test);
int		jp_test_tab(int *tab);

#endif
