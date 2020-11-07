/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 14:31:26 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/29 14:31:27 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE	32768
# define ERROR_MAP		{ft_putstr(argv[i]);ft_putstr(": map error");}

int						ft_atoi(char *str);
void					ft_stdin(int file);
void					ft_putchar(char c);
void					ft_putstr(char *str);
void					ft_putnbr(int nb);
char					*read_map(int file, char *argv);
int						check_valid_map(char *str_map);
void					kwame_is_life();

#endif
