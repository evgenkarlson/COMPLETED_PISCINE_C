/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/20 11:35:39 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/20 22:43:51 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include "ft_list.h"
# include "ft_string.h"
# include "ft_colle.h"
# include "ft_print.h"

char	*jp_check(char *str, char *cha);
void	jp_print_result(char *str);
int		*jp_get_size(char *str);

#endif
