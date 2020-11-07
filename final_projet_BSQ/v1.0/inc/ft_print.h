/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 12:37:01 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/23 18:00:53 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JP_PRINT_H
# define JP_PRINT_H

# include <unistd.h>
# include "ft_string.h"

void	jp_putchar(char c);
void	jp_putstr(char *str);
void	jp_puterr(char *str);

#endif
