/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 22:52:27 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/25 22:52:27 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# define BUF_SIZE 32

char						*g_progname;
const char					*ft_strerror(int errnum);
void						ft_putchar(char c);
void						ft_putstr(const char *str);
int							ft_display_custom_error(int eno, char *argv);
#endif
